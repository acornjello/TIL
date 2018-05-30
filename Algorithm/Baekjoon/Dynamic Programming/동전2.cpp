#include<iostream>
#include<string.h>
#include<algorithm>
#define MAX_VAL 10001
using namespace std;

int N, K, ans;
int mem[10001], coin[101];
int dp(int m) {
	if (m == 0) return 0;
	if (mem[m] != -1) return mem[m];

	mem[m] = MAX_VAL;
	for (int i = 1; i <= N; i++) {
		if(m-coin[i] >= 0)
			mem[m] = min(mem[m], dp(m - coin[i]) + 1);
		else break;
	}
	return mem[m];
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
		cin >> coin[i];

	sort(coin, coin + N);

	memset(mem, -1, sizeof(mem));
	ans = dp(K);
	cout << ( (ans == MAX_VAL) ? -1 : ans );

	return 0;
}