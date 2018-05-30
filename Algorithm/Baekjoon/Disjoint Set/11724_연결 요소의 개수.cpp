#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> node(1001, vector<int>(1001));
vector<bool> visited(1001);
int N, M;
int connected;
void Input() {
	int u, v;

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);

	}
}
void DFS(int v) {
	visited[v] = true;
	for (auto iter : node[v]) {
		if (!visited[iter]) DFS(iter);
	}
}
int main() {

	Input();
	
	for (int i = 1; i <= N; i++)	{
		if (!visited[i]) {
			DFS(i);
			connected++;
		}
	}

	cout << connected << endl;

	
	return 0;
}

