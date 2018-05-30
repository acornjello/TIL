#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

vector<int> dp(1001);
vector<int> score(1001);
int N;


int main() {
	int M=0, m=10000;
	cin >> N;

	for (int i = 1; i <= N; i++) {
			cin >> score[i];
			M = 0;
			m = 10000;
		for (int j = i; j >= 1; j--) {
			M = max(M, score[j]);
			m = min(m, score[j]);
			dp[i] = max(dp[i], dp[j - 1] + M - m);
		}
	}


	cout << dp[N] << endl;


	return 0;
}