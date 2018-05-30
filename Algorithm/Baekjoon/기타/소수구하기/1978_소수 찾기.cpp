#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main() {
	int N, prime=0,num, cnt=0;
	cin >> N;
	while (N--) {
		cin >> num;
		for (int i = 1; i <= sqrt(num); i++) {
			if (i != 1 && (num % i) == 0) {
				break;
			}
			else if (num != 1 && i == (int)sqrt(num)) {
				prime = 1;
			}
		}
		if (prime == 1) {	
			cnt++;
			prime = 0;
		}
	}
	cout << cnt << endl;


	return 0;
}