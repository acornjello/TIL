#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;


int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	int N, K;
	int mem[10001], coin[101];

	memset(mem, 0, sizeof(mem));

	cin >> N >> K;

	for (int i = 1; i <= N; ++i) {
		cin >> coin[i];
	}

	sort(coin, coin + N);
	
	mem[0] = 1;
	for (int i = 1; i<=N; ++i) {
		for(int j=0; j<=K; ++j) {
			if (j - coin[i] >= 0) mem[j] = mem[j] + mem[j - coin[i]];
		}
	}
	cout << mem[K];

	return 0;
}
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int N, K, ans;
int mem[10001], coin[101];

int dp(int money, int idx) {
if(money < 0 || idx > N) return 0;
if (money == 0) return 1;
if (mem[money] != -1) return mem[money];

mem[money] = 0;
int num = 0;
while (true) {
mem[money] += dp(idx+1, money - (coin[idx] * num));
if (money - (coin[idx] * num) < 0) break;
num++;
}

return mem[money];
}

int main() {
cin.tie(0); ios_base::sync_with_stdio(false);
for (int i = 0; i < 10001; ++i)
mem[i] = -1;

cin >> N >> K;

for (int i = 1; i <= N; ++i) {
cin >> coin[i];
}

sort(coin, coin + N);

mem[0] = 1;
for (int j = 1; j <= N; j++) {
for(int i=0; i<=K; i++) {
if (i - coin[j] >= 0) mem[i] = mem[i] + mem[i - coin[j]];
}
}

cout << mem[K];

return 0;
}
*/