#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;

	vector<int> v(5, 0);
	v[1] = -1;
	v[4] = 1;
	for (int i = 0; i < str.length(); i++) {
		switch (str[i]) {
		case 'A':
			swap(v[1], v[2]); break;
		case 'B':
			swap(v[1], v[3]); break;
		case 'C':
			swap(v[1], v[4]); break;
		case 'D':
			swap(v[2], v[3]); break;
		case 'E':
			swap(v[2], v[4]); break;
		case 'F':
			swap(v[3], v[4]); break;
		default: break;
		}
	}
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == -1)	cout << i << endl;
	}
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == 1)	cout << i << endl;
	}
}