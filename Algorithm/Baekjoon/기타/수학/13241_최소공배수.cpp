#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	if (a > b) swap(a, b);
	b = b%a;
	return gcd(a, b);
}

int main() {

	long long a, b, ans;
	
	scanf("%lld %lld", &a, &b);

	ans = a * b / gcd(a, b);

	printf("%lld\n", ans);

	return 0;
}