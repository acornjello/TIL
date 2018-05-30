/*
int fibo[41][2];

int main(void){
int n, k;
scanf("%d", &n);
fibo[0][0] = 1;
fibo[0][1] = 0;
fibo[1][0] = 0;
fibo[1][1] = 1;
int i;
for(i = 2 ; i < 41 ; i++){
fibo[i][0] = fibo[i-1][0] + fibo[i-2][0];
fibo[i][1] = fibo[i-1][1] + fibo[i-2][1];
}
for(i = 0 ; i < n ; i++){
scanf("%d", &k);
printf("%d %d\n", fibo[k][0], fibo[k][1]);
}
return 0;
}


*/

#include<iostream>
using namespace std;

int cntZero, cntOne;
int nzero[41], none[41];
bool checked[41];
void fibonacci(int n) {
	if (checked[n]) {
		cntZero += nzero[n];
		cntOne += none[n];
		return ;
	}

	if (n == 0) {
		cntZero++;
		return;
	}
	else if (n == 1) {
		cntOne++;
		return;
	}
	else {
		fibonacci(n - 1);
		fibonacci(n - 2);
	}
}

int main() {

	int T, t;

	cin >> T;

	for(int i=0; i<T; i++) {
		cin >> t;

		if (!checked[t]) {
			cntZero = 0;  cntOne = 0;
			fibonacci(t);
			checked[t] = true;
			nzero[t] = cntZero; none[t] = cntOne;
		}
		cout << nzero[t] << " " << none[t] << "\n";

	}

	return 0;
}