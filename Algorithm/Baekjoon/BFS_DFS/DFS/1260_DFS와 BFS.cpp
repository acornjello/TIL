#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M;
vector<bool> visited(1001);
vector<bool> visited2(1001);
queue<int> q;
vector<int> node[1001];

void DFS(int node);	// DFS�� ���� node����� iter�� !D[iter]	// visit�� �ǹ� : ������
void BFS();			// visited�� �ǹ� : �湮�� �����̶�� ť���� �־��� �ߺ��� �ȵǰ�

int main() {
	int v1, v2, v;
	cin >> N >> M >> v;

	for (int i = 1; i <= M; i++) {
		cin >> v1 >> v2;
		node[v1].push_back(v2);
		node[v2].push_back(v1);
	}

	DFS(v);
	cout << endl;

	q.push(v);
	visited2[v] = true;
	BFS();

	return 0;
}

void DFS(int v) {
	visited[v] = true;
	cout << v << " ";
	for (auto iter : node[v]) {
		if (!visited[iter]) DFS(iter);
	}

}

void BFS() {
	while (!q.empty()) {
		for (int i = 1; i <= N; i++) {
			if (node[q.front()][i] && !visited2[i]) {
				visited2[i] = true;
				q.push(i);
			}
		}
		cout << q.front() << " ";
		q.pop();
	}
}
