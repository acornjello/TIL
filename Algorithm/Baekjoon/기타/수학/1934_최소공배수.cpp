#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	if (a > b) swap(a, b);
	b = b%a;
	return gcd(b, a%b);
}

int main() {

	int a, b;
	int answer;
	int T;

	cin >> T;

	while (T--) {

		scanf("%d %d", &a, &b);
		answer = (a * b) / gcd(a, b) ;
		printf("%d\n", answer);

	}

	return 0;
}