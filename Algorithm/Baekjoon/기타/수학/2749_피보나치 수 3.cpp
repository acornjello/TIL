#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

#define MOD 1000000LL

struct Matrix {
	long long a, b, c, d;

	Matrix operator* (Matrix m) {
		Matrix result;

		result.a = ((this->a*m.a) + (this->b * m.c)) % MOD;
		result.b = ((this->a*m.b) + (this->b * m.d)) % MOD;
		result.c = ((this->c*m.a) + (this->d * m.c)) % MOD;
		result.d = ((this->c*m.b) + (this->d * m.d)) % MOD;

		return result;
	}
	/*
	Matrix operator% (long long mod) {
		this->a = (this->a % mod);
		this->b = (this->b % mod);
		this->c = (this->c % mod);
		this->d = (this->d % mod);

		return *this;
	}*/
};


Matrix calFibo(long long k) {

	Matrix ans = { 1, 0, 0, 1 }, now = { 1, 1, 1, 0 };

	while (k > 0) {
		if (k % 2 == 1) {
			ans = ans * now;
			k = k - 1;
		}
		now = now * now;
		k = k / 2;
	}

	return ans;
}

int main() {
	long long N;
	vector<long long> fibo;
	
	cin >> N;

	if (N == 0)
		cout << 0;
	else {
		Matrix ans = calFibo(N - 1);
		cout << ans.a;
	}

	return 0;
} 