#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int minLength = 10000, len, round;
	int N, j, m, r;

	cin >> N;

	for(int i=1; i<=N; i++) {
		cin >> j >> m;
		r = (j - 1) % (m + 1);
		len = (j - r) / (m + 1) * 2 + 2;
		if (minLength > len) {
			minLength = len;
			round = i;
		}
	}
	cout << round << " " << minLength << endl;
}