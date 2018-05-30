#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main() {
	int N, val;
	queue<int> q;
	string cmd;
	cin >> N;
	while (N--) {
		cin >> cmd;

		if (cmd == "push") {
			cin >> val;
			q.push(val);
		}
		else if (cmd == "pop") {
			if (!q.empty()) {
				cout << q.front() << endl;
				q.pop();
			}
			else
				cout << "-1" << endl;
		}
		else if (cmd == "size") {
			cout << q.size() << endl;
		}
		else if (cmd == "empty") {
			cout << q.empty() << endl;
		}
		else if (cmd == "front") {
			if (!q.empty())
				cout << q.front() << endl;
			else
				cout << "-1" << endl;
		}
		else if (cmd == "back"){
			if(!q.empty()) 
				cout << q.back() << endl;
			else 
				cout << "-1" << endl;
		}
	}

	return 0;
}