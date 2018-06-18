#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

struct pos {
	int r, c;
	int cnt;
};
int R, C;
int water[1501][1501], dr[4] = { 1, -1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };
char frozen[1501][1501];
bool visited[1501][1501];

pos start, dest;

void waterBFS() {
	queue<pos> q;
	
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (frozen[i][j] == '.') {
				q.push({ i, j, 0 });
				water[i][j] = 0;
				visited[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		pos curr = q.front();
		water[curr.r][curr.c] = curr.cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextR = curr.r + dr[i];
			int nextC = curr.c + dc[i];

			if (nextR > 0 && nextR <= R && nextC > 0 && nextC <= C
				&& !visited[nextR][nextC]) {	
				q.push({ nextR, nextC, curr.cnt + 1 });
				visited[nextR][nextC] = true;
			}
		}

	}

}

bool bfs(int limit) {

	queue<pos> q;
	visited[start.r][start.c] = true;
	q.push({ start.r, start.c });
	
	while (!q.empty()) {
		pos curr = q.front();
		q.pop();

		if (curr.r == dest.r && curr.c == dest.c) return true;


		for (int i = 0; i < 4; i++) {
			int nextR = curr.r + dr[i];
			int nextC = curr.c + dc[i];

			if (nextR > 0 && nextR <= R && nextC > 0 && nextC <= C
				&& !visited[nextR][nextC] && water[nextR][nextC] <= limit) {
					visited[nextR][nextC] = true;
					q.push({ nextR, nextC });
			}
		}
	}

	return false;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> R >> C;

	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			cin >> frozen[i][j];
	
			if (frozen[i][j] == 'L') {
				if (frozen[start.r][start.c] != '.') {
					start.r = i; start.c = j;
					frozen[start.r][start.c] = '.';
				}
				else {
					
					dest.r = i; dest.c = j;
					frozen[dest.r][dest.c] = '.';
				}
			} 
		}
	}

	waterBFS();

	int low = 0, high = R + C;
	int mid;

	while (low <= high) {
		memset(visited, false, sizeof(visited));

		mid = (low + high) / 2;

		if (bfs(mid))	
			high = mid - 1;
		
		else 
			low = mid + 1;
	}
	cout << low;

	return 0;
}
