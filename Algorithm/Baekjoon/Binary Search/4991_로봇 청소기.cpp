/*
집배원 한상덕과 비슷
시작 시점 + 10곳 더러운 곳
dist [10][10] 다 구하기	// 외판원순회
binary search

*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;


struct info {
	int r, c;
	int cnt;
};
const int M = 401;
int R, C, D;
int sr[11], sc[11], dist[11][11], dp[11][1 << 11];
int dr[4] = { 1, -1, 0, 0 }, dc[4] = { 0, 0, 1, -1 };
char room[20][20];
bool visited[20][20];




bool isValid(int r, int c) {
	if (r >= R || r < 0 || c >= C || c < 0) return false;
	return true;
}

int go(int src, int visited) {

	if (visited == (1 << D) - 1) {
		return dp[src][visited];
	}

	if (dp[src][visited] != M) return dp[src][visited];
	
	for (int i = 1; i <= D; i++) {
		bool visitedNext = (visited & 1 << (i-1));
		
		if (!visitedNext && dist[src][i] != M) {
			int newVisit = visited | (1 << (i - 1));
			dp[src][visited] = min(dp[src][visited], dist[src][i] + go(i, newVisit));
		}
			
	}
	return dp[src][visited];


}

void solve2() {

	memset(dist, M, sizeof(dist));
	memset(dp, M, sizeof(dp));

	for(int src = 0; src < D; src++) {
		memset(visited, false, sizeof(visited));

		queue<info> q;
		q.push({ sr[src], sc[src], 0});
		visited[sr[src]][sc[src]] = true;

		while (!q.empty()) {
			info curr = q.front();
			q.pop();

			for (int i = 1; i <= D; i++) {
				if (curr.r == sr[i] && curr.c == sc[i]) {
					dist[src][i] = curr.cnt;
					dist[i][src] = curr.cnt; break;
				}
			}

			for (int i = 0; i < 4; i++) {
				int nextR = curr.r + dr[i];
				int nextC = curr.c + dc[i];

			
				if (isValid(nextR, nextC) && !visited[nextR][nextC]) {
					q.push({ nextR, nextC, curr.cnt + 1 });
					visited[nextR][nextC] = true;
				}
			}
		}
	}

	int ans = M;
	// 외판원
	ans = min (ans, go(0, 0));

	if (ans == M) cout << "-1\n";
	else cout << ans<<"\n";


}


int main() {


	while (true) {
		
		cin >> C >> R;
		if (C == 0 || R == 0) break;
		D = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> room[i][j];

				if (room[i][j] == 'o') {
					sr[0] = i; sc[0] = j;
				}
				else if (room[i][j] == '*') {
					D++;
					sr[D] = i; sc[D] = j;
				}
			}
		}
		int visited = ((1 << D) - 1) & 1;
		int src = 1;

		solve2();
	}

	return 0;
}
