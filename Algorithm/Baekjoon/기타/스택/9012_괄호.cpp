#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	int T, i;
	string br;
	stack<char> st;
	cin >> T;
	while (T--) {
		cin >> br;
		i = 0;
		while(i<br.length()) {
			if (br[i] == '(') {
				st.push(br[i]);
			}
			else if (br[i] == ')') {
				if (st.size() != 0 && st.top() == '(') {
					st.pop();
				}
				else {
					while (!st.empty()) {
						st.pop();
					}
					cout << "NO\n";
					break;
				}
			}
			i++;
			if (i == br.length() && !st.empty()) {
				cout << "NO\n";
				while (!st.empty()) {
					st.pop();
				}
			}
			else if(i==br.length() && st.empty()) cout << "YES\n";
		}
		
	}
	
	return 0;
}
