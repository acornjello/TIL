#include<iostream>
#include<algorithm>
#define MAX_VAL 10000001

using namespace std;

//int mem[MAX_VAL];
//
//
//int dp(int money) {
//	if (mem[money] != MAX_VAL) return mem[money];
//	if (money == 0) return mem[money] = 0;
//	
//	for (int i = N; i >= 1; i--) {
//		if (money - A[i] < 0) continue;
//		mem[money] = min(mem[money], dp(money - A[i]) + 1);
//	}
//	return mem[money];
//}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N, K;
	int A[11];
	cin >> N >> K;

	int ans = 0;

	/*for (int i = 0; i < MAX_VAL; ++i)
		mem[i] = MAX_VAL;*/

	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}

	/*if (K > MAX_VAL) {
		ans = ans + (K / A[N]);
		K = K % A[N];
	}
	ans += dp(K);
	cout << ans;*/

	while (K > 0) {
		ans = ans + (K / A[N]);
		K = K%A[N];
		N--;
	}
	cout << ans;
	return 0;
}