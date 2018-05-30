#include<iostream>
#include<queue>
#define MOD 1000000007
using namespace std;

void test_case() {
	int n, k;
	int sum = 1;
	queue<int> q;
	vector<int> fibo(1000001);

	cin >> n >> k;
	
	if (k == n) {
		cout << 1 << endl;
		return;
	}
	else if (k < n) {
		cout << 0 << endl;
		return;
	}

	for (int i = 1; i < n; i++) {
		q.push(0);
		fibo[i] = 0;
	}
	q.push(1);
	fibo[n] = 1;

	for (int i = n + 1; i < k; i++) {
		q.push(sum);
		fibo[i] = sum;

		sum = (sum + sum) % MOD;
		sum = (sum - q.front() + MOD) % MOD;
		q.pop();
	}
	
	cout << sum << endl;	
}


int main() {
	int t;

	cin >> t;


	while (t--) {
		test_case();
	}
	
}
