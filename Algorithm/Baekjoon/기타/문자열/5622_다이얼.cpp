#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string dial;
	vector<int> alpha{ 2 , 2 , 2 ,  3 , 3 , 3 ,  4 , 4 , 4 ,  5 , 5 , 5 , 
				 6 , 6 , 6 ,  7 , 7 , 7 ,  7 ,  8 , 8 , 8 ,  9 , 9 , 9 ,  9 };
	int time=0;

	cin >> dial;

	for (int i = 0; i < dial.length(); i++) {
		
		time += alpha[(dial[i] - 'A')] + 1;		
		
	}
	cout << time << endl;
	return 0;

}