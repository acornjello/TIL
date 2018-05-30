#include<iostream>
#include<vector>
using namespace std;

int dp[1001][2][3]; // 일수 지각 결석
int N;

int DP(int o, int l, int a) {

	if (dp[o][l][a] != 0) return dp[o][l][a];
	if (o == N) return 1;
	
	if (l < 1) {
		dp[o][l][a] += DP(o + 1, l + 1, 0);
	}
	if (a < 2) {
		dp[o][l][a] += DP(o + 1, l, a + 1);
	}

	dp[o][l][a] += DP(o + 1, l, 0);
	return dp[o][l][a] % 1000000;
}

int main() {

	cin >> N;

	cout << DP(0, 0, 0) << endl;

	return 0;
}