#include<iostream>

using namespace std;


int main() {
	int N, K, S, Y;
	int male[7] = { 0 }, female[7] = { 0 };
	int room = 0;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> S >> Y;

		if (S == 0) {
			female[Y]++;
			female[Y] = female[Y] % K;
			if (female[Y] == 1)
				room++;
		}
		else {
			male[Y]++;
			male[Y] = male[Y] % K;
			if (male[Y] == 1)
				room++;
		}
	}

	cout << room << endl;

}