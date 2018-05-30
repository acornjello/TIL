#include<iostream>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

enum status { NONE, HORIZONTAL, VIRTICAL };

struct Wood {
	int y, x;
	status direction = NONE;
	int cnt = 0;
};

int N;
char maze[51][51];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
Wood wood, dest;
bool visited[51][51][3];

bool isValid( int sx, int sy, int dir) {
	int tx, ty;
	if ( dir == (int) HORIZONTAL ) {
		tx = 1; ty = 0;
	}
	else {
		tx = 0; ty = 1;
	}

	if (sx-tx > 0 && sx+tx <= N && sy-ty > 0 && sy+ty <= N
		&& maze[sy-ty][sx-tx] == '0' && maze[sy+ty][sx+tx] == '0'
		&& maze[sy][sx] == '0' && !visited[sy][sx][dir]) {
		return true;
	}
	else {
		return false;
	}
}

bool isValidToTurn(int cx, int cy) {

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if ( cy+i < 1 || cy+i > N || cx + j < 1 || cx + j > N || maze[cy + i][cx + j] != '0')
				return false;
		}
	}
	return true;

}

int bfs() {
	int ans = 0;
	queue<Wood> q;

	visited[wood.y][wood.x][wood.direction] = true;
	q.push(wood);
	
	while (!q.empty()) {
		wood = q.front();
		int centerY = wood.y;
		int centerX = wood.x;
		status dir = wood.direction;
		int cnt = wood.cnt;

		q.pop();

		if (centerX == dest.x && centerY == dest.y && dir == dest.direction) {
			ans = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nextX= centerX + dx[i];
			int nextY = centerY + dy[i];

			if ( isValid(nextX, nextY, dir) ) {
				visited[nextY][nextX][dir] = true;
				q.push({ nextY, nextX, dir, cnt + 1 });
			}
		}
		
		int plus = (int) pow(-1, (int) dir);
		status newDir = (dir == HORIZONTAL) ? VIRTICAL : HORIZONTAL;
		if ( isValidToTurn(centerX, centerY) && !visited[centerY][centerX][newDir] ) {
			visited[centerY][centerX][newDir] = true;
			q.push({ centerY, centerX, newDir, cnt + 1 });
		}

	}
	return ans;
}

int main() {

	cin >> N;

	for(int i=1; i<=N; i++) {
		for (int j = 1; j<=N; j++) {
			cin >> maze[i][j];
		}
	}
	for (int i = 1; i<=N; i++) {
		for (int j = 1; j<=N; j++) {
			if (wood.direction == NONE && maze[i][j] == 'B') {
				if (j <= N - 2 && maze[i][j + 1] == 'B') {
					wood = { i, j + 1, HORIZONTAL, 0 };
				}
				else if (i <= N - 2 && maze[i + 1][j] == 'B') {
					wood = { i + 1, j, VIRTICAL, 0 };
				}
			}
			else if (dest.direction == NONE && maze[i][j] == 'E') {
				if (j <= N - 2 && maze[i][j + 1] == 'E') {
					dest = { i, j + 1, HORIZONTAL, 0 };
				}
				else if (i <= N - 2 && maze[i + 1][j] == 'E') {
					dest = { i + 1, j, VIRTICAL, 0 };
				}
			}
			maze[i][j] = (maze[i][j] != '1') ? '0' : '1';
		}
	}
	cout << bfs();

	return 0;
}