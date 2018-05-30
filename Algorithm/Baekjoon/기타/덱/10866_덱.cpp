#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main() {
	int N, val;
	string cmd;
	deque<int> dq;

	cin >> N;

	while (N--) {
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> val;
			dq.push_front(val);
		}
		else if (cmd == "push_back") {
			cin >> val;
			dq.push_back(val);
		}
		else if (cmd == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << endl;
				dq.pop_front();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (cmd == "pop_back") {
			if(!dq.empty()) {
				cout << dq.back() << endl;
				dq.pop_back();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (cmd == "size") {
			cout << dq.size() << endl;
		}
		else if (cmd == "empty") {
			cout << dq.empty() << endl;
		}
		else if (cmd == "front") {
			if(!dq.empty()) cout << dq.front() << endl;
			else cout << "-1\n";
		}
		else if (cmd == "back") {
			if (!dq.empty()) cout << dq.back() << endl;
			else cout << "-1\n";
		}
	}



	return 0;
}
