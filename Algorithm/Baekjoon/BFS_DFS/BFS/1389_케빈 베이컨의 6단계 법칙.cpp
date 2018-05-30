#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> node[101];
vector<int> visited(101);
queue<int> q;

int N, M;

void Input() {
	int u, v;

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
}

void BFS() {
	fill(visited.begin(), visited.end(), -1);
	visited[q.front()] = 0;
	while (!q.empty()) {
		for (auto iter : node[q.front()]) {
			if (visited[iter] == -1) {
				visited[iter] = visited[q.front()] + 1;
				q.push(iter);
			}
		}
		q.pop();
	}
}
int main() {
	int relation = 1e6, sum, ans;
	Input();

	for (int i = 1; i <= N; i++) {
		sum = 0;
		q.push(i);
		BFS();

		for (int j = 1; j <= N; j++)
			sum += visited[j];
		if (relation > sum) {
			relation = sum;
			ans = i;
		}
	}
	cout << ans << endl;

	return 0;
}
