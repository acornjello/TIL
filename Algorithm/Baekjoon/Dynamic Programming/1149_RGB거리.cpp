#include<iostream>
#include<algorithm>
using namespace std;


int main() {

	int N;
	int house[1001][4], dp[1001][4];

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> house[i][j];
		}
	}

	dp[0][1] = dp[0][2] = dp[0][3] = 0;

	for(int i=1; i<=N; i++) {
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + house[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + house[i][2];
		dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][3];
	}

	cout << min( min(dp[N][1], dp[N][2]), dp[N][3] );

	return 0;

}
