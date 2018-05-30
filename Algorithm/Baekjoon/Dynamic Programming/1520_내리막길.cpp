#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int N, M;
int maze[501][501];
int mem[501][501];
int dc[4] = { 0, 0, -1, 1 }, dr[4] = { 1, -1, 0, 0 };

int go(int r, int c) {
	if (r == N - 1 && c == M - 1) return 1;
	if (mem[r][c] != -1) return mem[r][c];

	mem[r][c] = 0;

	for (int i = 0; i < 4; i++) {
		int nextR = r + dr[i];
		int nextC = c + dc[i];

		if ( nextR < N && nextR >= 0 && nextC < M && nextC >= 0 
				&& maze[nextR][nextC] < maze[r][c]  ) {
			mem[r][c] = mem[r][c] + go(nextR, nextC);
		}
	}

	return mem[r][c];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maze[i][j];
		}
	}
	memset(mem, -1, 501 * 501 * sizeof(int));
	cout << go(0, 0) <<"\n";

	return 0;
}