#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<vector<int>> node(20001, vector<int>());
vector<int> status(20001, 0);

bool DFS(int v, int s) {
	status[v] = s;

	for (auto iter : node[v]) {
		if (status[iter] == s) {
			return false;
		}
		if (status[iter] == 0 && !DFS(iter, -s)) {
			return false;
		}
	}
	return true;
}


int main() {

	int T, V, E;
	int v1, v2;


	fill(status.begin(), status.end(), 0);
	cin >> T;


	while (T--) {
		cin >> V >> E;
		bool bi = false;
		fill(status.begin(), status.end(), 0);
		for (int i = 0; i < node.size(); i++)
			node[i].resize(0);
		while (E--) {
			cin >> v1 >> v2;
			node[v1].push_back(v2);
			node[v2].push_back(v1);
		}

		for (int i = 1; i <= V; i++) {
			if (status[i] == 0) {
				if (!DFS(i, 1)) {
					cout << "NO" << endl;
					bi = true;
					break;
				}
			}
		}
		if (!bi) {
			cout << "YES" << endl;
		}
	}

	return 0;
}
