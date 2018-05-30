#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
char rgb[101][101];
bool visited[101][101][2];
int dx[4] = { 0, 0, -1, 1 }, dy[4] = { 1, -1, 0, 0 };

void dfs(int y, int x, int type) {

	visited[y][x][type] = true;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N
			&& !visited[nextY][nextX][type]) {
			if (type == 0) {
				if (rgb[nextY][nextX] == rgb[y][x])
					dfs(nextY, nextX, type);
			}
			else if (type == 1) {
				if (rgb[nextY][nextX] == rgb[y][x])
					dfs(nextY, nextX, type);
				else if ((rgb[y][x] == 'R' && rgb[nextY][nextX] == 'G')
					|| (rgb[y][x] == 'G' && rgb[nextY][nextX] == 'R'))
					dfs(nextY, nextX, type);
			}
		}
	}

}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cin >> rgb[i][j];

		}
	}
	
	int cntR_G_B = 0, cntRG_B = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j][0]) {
				dfs(i, j, 0);
				cntR_G_B++;
			}
			if (!visited[i][j][1]) {
				dfs(i, j, 1);
				cntRG_B++;
			}
		}
	}

	cout << cntR_G_B << " " << cntRG_B;

	return 0;
}