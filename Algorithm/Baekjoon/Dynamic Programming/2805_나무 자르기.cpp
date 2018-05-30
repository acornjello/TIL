#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

long long _MAX = 2e9;
int N, M;
long long height[10000001];
long long high = 0ll, low = 0ll;
long long ans = 0ll;
void solve() {
	long long mid;
	while (low <= high) {
		mid = (high + low) / 2ll;
		long long sum = 0ll;
		bool isOk = false;
		for (auto h : height) {
			sum += (mid < h) ? h - mid : 0ll;
			if (sum >= _MAX) break;
		}
		if (sum == M) { ans = mid; break; }
		if (sum < M) {
			high = mid - 1;
		}
		else {
			ans = mid;
			low = mid + 1; 
		}
	}
	
	cout << ans;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> height[i];
		high = max(high, height[i]);
	}
	solve();

}