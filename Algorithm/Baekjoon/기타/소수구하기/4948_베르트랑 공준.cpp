#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int N, cnt;
	
	while(true) {
		cin >> N;
		if (N == 0) return 0;
		cnt = 0;
		for (int i = N+1; i <= 2*N; i++) {
			for (int j = 1; j <= sqrt(i); j++) {
				if (i == 1 || (i%j == 0 && j != 1)) {
					break;
				}
				if (j == (int)sqrt(i)) {
					cnt++;				
				}
			}
		}
		printf("%d\n", cnt);
	
	}
	return 0;
}