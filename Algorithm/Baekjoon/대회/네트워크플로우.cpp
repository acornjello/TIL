#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> node;
vector<int> pred, cow;
vector<bool> checked, visited;

int N, M;

bool dfs(int x) {
	visited[x] = true;
	for (auto iter : node[x]) {
			if (pred[iter] == -1 || (!visited[pred[iter]]&&dfs(pred[iter])) ) {
				cow[x] = iter;
				pred[iter] = x;
				return true;
			}
		}
	}
	return false;
}

int flow() {
	int ans = 0;
	
	fill(pred.begin(), pred.end(), -1);
	fill(checked.begin(), checked.end(), false);
	for (int i = 1; i <= N; i++) {
		//if(cow[i] == -1){
			fill(visited.begin(), visited.end(), false);
			if (dfs(i)) ans++;
		//}
		
	}
	return ans;
}


int main() {
	int c;
	cin >> N >> M;

	node.resize(N+1);
	visited.resize(M+1);
	pred.resize(N + 1);
	cow.resize(N + 1);
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