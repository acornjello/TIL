#include<iostream>

#define maxN 10000001

using namespace std;



int main() {
	
	
	bool selfNum[maxN];

	for (int i = 1; i <= maxN; i++) {
		selfNum[i] = true;
	}

	for (int i = 1; i <= maxN; i++) {
		int sum = i;
		int div = 10;
		int rest = i;
		while ((rest / div) > 0) {
			sum = sum + (i % div);
			rest = i / div;
		}
		if (sum <= maxN) selfNum[sum] = false;
	}

	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;
		if (selfNum[N] == true) cout << "Self" << endl;
		else cout << "No" << endl;
	}

	return 0;
}