#include<iostream>
#include<algorithm>
using namespace std;

int N, ans;
bool c[16], d1[31], d2[31];

void solve(int y) {
	if (y > N) {
		ans++; return;
	}
	for (int i = 1; i <= N; i++) {
		if (c[i] | d1[y + i] | d2[y - i + N]) continue;
		c[i] = d1[y + i] = d2[y - i + N] = true;
		solve(y+1);
		c[i] = d1[y + i] = d2[y - i + N] = false;
	}
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N;
	solve(1);
	cout << ans;

	return 0;
}