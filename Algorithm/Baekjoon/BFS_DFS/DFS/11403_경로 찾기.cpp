#include<iostream>
#include<vector>
using namespace std;

void DFS(int);

vector<vector<int>> G(101, vector<int>(101, 0));
vector<vector<int>> M(101, vector<int>(101, 0));
vector<int> visited(101, 0);

int N;
void Input() {
	int e;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> e;
			G[i][j] = e;
		}
	}
}
void printResult() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}
void DFS(int v) {
	for (int i = 1; i <= N; i++) {
		if (G[v][i] && !visited[i]) {
			visited[i] = 1;
			DFS(i);
		}
	}
}

int main() {
	Input();

	for (int i = 1; i <= N; i++) {
		DFS(i);
		for (int j = 1; j <= N; j++) {
			M[i][j] = visited[j];
		}
		visited.clear();
		visited.resize(101);
	}

	printResult();

	return 0;
}

