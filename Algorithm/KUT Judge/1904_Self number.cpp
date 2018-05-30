#include<iostream>
#include<string>

using namespace std;

int main() {

	int T, N;
	bool isSelfNum = true;
	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 1; i <= 70; i++) {
			int div = 10;
			int sum = N - i;
			int result = N - i;
			while (result > 0) {
				sum += result % div;
				result = result / div;
			}
			if (sum == N) {
				isSelfNum = false;
				break;
			}
		}
		if( isSelfNum )
			cout << "Self\n";
		else
			cout << "No\n";
	}

	return 0;
}