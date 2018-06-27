#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> node;
vector<int> cowIdxInShed;
vector<bool> shedChecked, cowChecked;

int N, M;

bool dfs(int curr_cow) {
	shedChecked[curr_cow] = true;
	for (auto iter : node[curr_cow]) {
		int exst_cow = cowIdxInShed[iter];
		if ( exst_cow == -1 || ( !shedChecked[exst_cow] && dfs(exst_cow) ) ) {
			cowChecked[curr_cow] = true;
			cowIdxInShed[iter] = curr_cow;
			return true;
		}
	}
	return false;
}

int flow() {
	int ans = 0;
	
	fill(cowIdxInShed.begin(), cowIdxInShed.end(), -1);
	fill(cowChecked.begin(), cowChecked.end(), false);
	for (int i = 1; i <= N; i++) {
		if (!cowChecked[i]) {
			fill(shedChecked.begin(), shedChecked.end(), false);
			if (dfs(i)) ans++;
		}
	}
	return ans;
}


int main() {
	int c;
	cin >> N >> M;

	node.resize(N+1);
	shedChecked.resize(M+1);
	cowChecked.resize(N + 1);
	cowIdxInShed.resize(N + 1);

	for (int i = 0; i < N; i++) {
		cin >> c;
		for (int j = 0; j < c; j++) {
			int tmp;
			cin >> tmp;
			node[i + 1].push_back(tmp);
		}
	}

	cout << flow();	
}