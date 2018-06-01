#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int height[50001], p[50001];
vector<int> adj[50001];


void bfs() {
	struct info {
		int idx;
		int height;
	};
	queue<info> q;
	q.push({ 1, 1 });
	p[1] = 1;
	height[1] = 1;
	while (!q.empty()) {
		info curr = q.front();
		q.pop();

		for (auto node : adj[curr.idx]) {
			if (p[node] == 0) {
				height[node] = curr.height + 1;
				p[node] = curr.idx;
				q.push({ node, curr.height + 1 });
			}
		}
	}
}

void solve(int u, int v) {
	
	if (height[u] < height[v])	swap(u, v);

	while (height[u] != height[v]) {
		u = p[u];
	}

	while (u != v) {
		u = p[u];
		v = p[v];
	}

	cout << u << "\n";

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int N,T, u, v;
	cin >> N;

	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs();

	cin >> T;
	while (T--) {
		cin >> u >> v;
		solve(u, v);
	}

}