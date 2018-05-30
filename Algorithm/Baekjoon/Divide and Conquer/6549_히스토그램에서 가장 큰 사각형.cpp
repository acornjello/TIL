#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long> h(100001, 0);

long long solve(int left, int right) {
	if (left == right) return h[left];
	int mid = (left + right) / 2;

	long long ret = max(solve(left, mid), solve(mid + 1, right));
	int lo = mid, hi = mid + 1;
	long long height = min(h[lo], h[hi]);

	ret = max(ret, height * 2);

	while (left < lo || hi < right) {
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}

		ret = max(ret, height * (hi - lo + 1));
	}

	return ret;
}

int main() {
	int n, height;
	while(1) {
		scanf("%d", &n);
		if (n != 0) {
			for (int i = 1; i <= n; i++) {
				scanf("%d", &h[i]);
			}
			printf("%ld\n", solve(1, n));
		}
		else
			break;
	}
	
}