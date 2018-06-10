#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

int N, danji;
char node[26][26];
vector<int> nHouse(500, 0);
bool visited[26][26];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };


void DFS(int y, int x) {
	visited[y][x] = true;
	nHouse[danji]++;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextY > 0 && nextY <= N && nextX > 0 && nextX <= N
			&& !visited[nextY][nextX] && node[nextY][nextX] == '1')
			DFS(nextY, nextX);
	}
}

int main() {
	char c;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> node[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j] && node[i][j] == '1') {
				danji++;
				DFS(i, j);
			}
		}
	}

	cout << danji << endl;
	if (danji != 0) {
		sort(nHouse.begin(), nHouse.end(), greater<int>());
		for (int i = danji - 1; i >= 0; i--) {
			cout << nHouse[i] << "\n";
		}
	}

	return 0;
}
