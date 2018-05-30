#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main() {
	int M, N, sum = 0;
	vector<int> v;
	
	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		for (int j = 1; j <= sqrt(i); j++) {
			if (i == 1 || (i%j == 0 && j != 1)) {
				break;
			}
			if (j == (int)sqrt(i)) {
				v.push_back(i);
				sum += i;
			}
		}
	}
	if (v.size() == 0)
		cout << "-1\n";
	else {
		cout << sum << endl;
		cout << v[0] << endl;
	}
	

	return 0;
}