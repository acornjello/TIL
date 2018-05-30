#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
int M, N;
int sx, sy, sdir, ex, ey, edir;
int maze[101][101];
int dx[5] = { 0, 1, -1, 0, 0 }, dy[5] = { 0, 0, 0, 1, -1 };
bool visited[101][101][5];

struct pos {
	int y, x;
	int dir;
	int cnt = 0;
};

int bfs() {
	int ans;
	queue<pos> q;

	visited[sy][sx][sdir] = true;
	q.push({ sy, sx, sdir, 0 });

	while (!q.empty()) {

		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		int cnt = q.front().cnt;
		q.pop();

		if (y == ey && x == ex && dir == edir) {
			ans = cnt;
			break;
		}

		for (int j = 1; j <= 3; j++) {
			int nextY = y + (dy[dir] * j);
			int nextX = x + (dx[dir] * j);

			if (nextY > 0 && nextY <= M && nextX > 0 && nextX <= N) {
				if (maze[nextY][nextX] == 0 && !visited[nextY][nextX][dir]) {
					visited[nextY][nextX][dir] = cnt + 1;
					q.push({ nextY, nextX, dir, cnt + 1 });
				}
				else if (maze[nextY][nextX] == 1) {
					break;
				}
			}

		}

		if (dir == 1 || dir == 2) {
			if (!visited[y][x][3]) {
				visited[y][x][3] = true;
				q.push({ y, x, 3, cnt + 1 });
			}
			if (!visited[y][x][4]) {
				visited[y][x][4] = true;
				q.push({ y, x, 4, cnt + 1 });
			}
		}
		else {
			if (!visited[y][x][1]) {
				visited[y][x][1] = true;
				q.push({ y, x, 1, cnt + 1 });
			}
			if (!visited[y][x][2]) {
				visited[y][x][2] = true;
				q.push({ y, x, 2, cnt + 1 });
			}
		}

	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> maze[i][j];
		}
	}

	cin >> sy >> sx >> sdir;
	cin >> ey >> ex >> edir;

	cout << bfs();

	return 0;
}