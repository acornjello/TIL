#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N, ans=0;
int tri[500][500];
int dp[500][500];
int go(int x, int y) {
	if (x >= N || y >= N) return 0;
	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = tri[y][x] + max(go(x + 1, y + 1), go(x, y + 1));

	return dp[y][x];
}


void solve() {

	memset(dp, -1, sizeof(dp));

	cout << go(0, 0);

}


int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	solve();


	return 0;
}