#include<iostream>

using namespace std;


int main() {
	
	int N;
	long long width = 0, height = 1;

	cin >> N;

	for (int i = 0; i < N; i++) {
		if (i % 2 == 1) {
			height = height + width;
		}
		else {
			width = width + height;
		}
		
	}
	cout << (width + height) * 2 << endl;

}