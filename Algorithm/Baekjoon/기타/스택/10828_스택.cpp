#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	int n, val;
	string cmd;
	stack<int> st;

	cin >> n;

	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> val;
			st.push(val);
		}
		else if (cmd == "pop") {
			if(!st.empty()) {
				cout << st.top() << endl;
				st.pop();
			}
			else
				cout << "-1" << endl;
		}
		else if (cmd == "size") {
			cout << st.size() << endl;
		}
		else if (cmd == "empty") {
			cout << st.empty() << endl;
		}
		else if (cmd == "top") {
			if (!st.empty())
				cout << st.top() << endl;
			else
				cout << "-1" << endl;
		}
		cmd = "";
	}
	
	

	return 0;
}