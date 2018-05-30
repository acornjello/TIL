#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {	
	string num1, num2;

	cin >> num1 >> num2 ;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	if (stoi(num1) < stoi(num2)) {
		cout << num2 << endl;
	}
	else {
		cout << num1 << endl;
	}
	return 0;
}