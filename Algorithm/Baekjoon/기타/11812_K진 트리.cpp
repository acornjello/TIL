#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	long long N, a, b;
	int K, Q;
	scanf("%lld %d %d", &N, &K, &Q);

	while (Q--) {
		scanf("%lld %lld", &a, &b);
		if (K<2) {
			printf("%lld\n", abs(a - b));
			continue;
		}
		int cnt = 0;
		while (a != b) {
			if (a < b) swap(a, b);

			a = (a + (K - 2)) / K;

			cnt++;
		}

		printf("%d\n", cnt);
		
	}
	return 0;
}