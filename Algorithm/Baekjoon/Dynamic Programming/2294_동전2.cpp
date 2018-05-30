#include<iostream>
#include<algorithm>
using namespace std;


int N, K;
int dp[10001];
int coin[101];


int  go(int money) {
	if (money < 0) return -1;
	if (dp[money] != 0) return dp[money];

	for (int i = 0; i < N; i++) {
		dp[money] = min( dp[money], go(money - coin[i]) + 1 );
	}


} 

int main() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
		dp[coin[i]] = 1;
	}

	go(K);

	return 0;
}
