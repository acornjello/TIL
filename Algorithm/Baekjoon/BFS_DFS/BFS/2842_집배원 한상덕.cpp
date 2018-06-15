#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

#define MAX_H 1000000
struct info {
	int y, x;
	int maxH;
};
int N, cntK, numK, px, py;
int height[51][51], mem[51][51];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
char town[51][51];
vector<int> h;
vector<info> k;

int bfs(int minH) {
	int cntK = 0, maxH = 0;
	bool visited[51][51];
	queue<info> q;
	
	memset(visited, false, sizeof(visited));
	memset(mem, MAX_H, sizeof(mem));
	
	q.push({ py, px, height[py][px] });
	mem[py][px] = height[py][px];

	
	while (!q.empty()) {
		info curr = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nextX = curr.x + dx[i];
			int nextY = curr.y + dy[i];

			if (nextX > 0 && nextX <= N && nextY > 0 && nextY <= N) {
				int temp = max(height[nextY][nextX], curr.maxH);

				if (!visited[nextY][nextX] && height[nextY][nextX] >= minH) {
					mem[nextY][nextX] = temp;
					visited[nextY][nextX] = true;
					q.push({ nextY, nextX, temp });
				}
				else if (visited[nextY][nextX] && temp < mem[nextY][nextX]) {
					mem[nextY][nextX] = temp;
					q.push({ nextY, nextX, temp });
				}
			}
		}
	}

	for (auto e : k) {
		if (!visited[e.y][e.x]) return MAX_H;
		maxH = max(maxH, mem[e.y][e.x]);
	}

	return maxH - minH;
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> town[i][j];
			if (town[i][j] == 'K') {
				k.push_back({ i, j });
			}
			else if (town[i][j] == 'P') {
				py = i; px = j;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> height[i][j];
			h.push_back(height[i][j]);
		}
	}

	sort(h.begin(), h.end());

	int ans = MAX_H;

	for (int i = 0; i < h.size(); i++) {
		if (h[i] > height[py][px]) break;
		if (i > 0 && h[i - 1] == h[i]) continue;

		ans = min(ans, bfs(h[i]));
	}
	cout << ans;

	return 0;
}