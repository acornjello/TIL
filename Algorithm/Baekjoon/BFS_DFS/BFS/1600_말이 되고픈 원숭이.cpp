#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct pos {
	int y;
	int x;
	int cntK = 0;
	int totCnt=0;
};
int K, W, H, ans;
int board[201][201];
int visited[201][201][31];
int hx[] = { 2, 2, 1, 1, -2, -2, -1, -1};
int hy[] = { 1, -1, 2, -2, 1, -1, 2, -2};
int mx[] = { 1, -1, 0, 0 };
int my[] = { 0, 0, -1, 1 };

int bfs() {

	queue<pos> q;
	visited[0][0][K] = true;
	q.push({ 0, 0, K });

	while (!q.empty()) {

		pos p = q.front();
		int x = p.x;
		int y = p.y;
		int cntK = p.cntK;
		int totCnt = p.totCnt;
		q.pop();

		if ( x == W - 1 && y == H - 1 ) {
			return totCnt;
		}

		for (int i = 0; i < 8; i++) {
			if (cntK - 1 < 0) break;
			int nextX = x + hx[i];
			int nextY = y + hy[i];

			if ( nextY >= 0 && nextY < H && nextX >= 0 && nextX < W && board[nextY][nextX] != 1
				&& !visited[nextY][nextX][cntK-1] ) {

				visited[nextY][nextX][cntK - 1] = true;
				q.push({ nextY, nextX, cntK - 1, totCnt + 1 });

			}
		}

		for (int i = 0; i < 4; i++) {
			int nextX = x + mx[i];
			int nextY = y + my[i];
			if (nextY >= 0 && nextY < H && nextX >= 0 && nextX < W && board[nextY][nextX] != 1
				&& !visited[nextY][nextX][cntK]) {

				visited[nextY][nextX][cntK] = true;
				q.push({ nextY, nextX, cntK, totCnt + 1 });

			}
		}
	}

	return -1;
}

int main() {

	cin >> K;
	cin >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> board[i][j];
		}
	}

	cout << bfs();

	return 0;
}