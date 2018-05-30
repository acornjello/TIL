#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<vector<int>> node(101, vector<int>(101));
vector<vector<int>> visited(101, vector<int>(101));

int N, minHeight = 0, maxHeight = INT_MIN;
int field[101] = { 0 };
int maxField = 0;
// dfs(idx, h)와 dfsall(h)구분
// map[] >> 일차원 x== i%N  y== i/N;

int tx[] = { 0, 0, 1, -1 };
int ty[] = { 1, -1, 0, 0 };

void Input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> node[i][j];
			maxHeight = max(maxHeight, node[i][j]);
		}
	}
}
void DFS(int x, int y, int h) {
	if ((x < 0 || x > N || y < 0 || y > N)) return;
	if (visited[y][x] || node[y][x] <= h)	return;

	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		DFS(x + tx[i], y + ty[i], h);
	}
}
void DfsAll() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j] && node[i][j] > minHeight) {
				field[minHeight]++;
				DFS(j, i, minHeight);
			}
		}
	}
	maxField = max(maxField, field[minHeight]);
}
int main() {


	Input();

	while (minHeight < maxHeight) {
		for (int i = 1; i <= N; i++) {
			fill(visited[i].begin(), visited[i].end(), false);
		}

		DfsAll();


		minHeight++;
	}

	cout << maxField << endl;

	return 0;
}