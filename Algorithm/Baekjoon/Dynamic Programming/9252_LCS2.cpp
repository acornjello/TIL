#include<iostream>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;

string s1, s2;
int mem[1001][1001];

int main() {

	stack<char> ans;
	
	cin >> s1;
	cin >> s2;
	
	for (int i = 0; i<s1.length(); i++) {
		for (int j = 0; j<s2.length(); j++) {
			if (s1[i] == s2[j])
				mem[i][j] = (i == 0 || j == 0) ? 1 : mem[i-1][j-1] + 1;
			else
				mem[i][j] = max((i == 0)? 0 : mem[i-1][j], (j == 0) ? 0 : mem[i][j-1]);
		}
	}

	cout << mem[s1.length() - 1][s2.length() - 1] << "\n";

	int i = s1.length() - 1, j = s2.length() - 1;

	while (i >= 0 && j >= 0) {
		if ( ((i==0) ? 0 : mem[i-1][j]) == ((j==0) ? 0 : mem[i][j-1])
			&& ((i==0) ? 0 : mem[i - 1][j]) != mem[i][j]) {
			ans.push(s1[i]);
			--i;
			--j;
		}
		if (mem[i][j] == mem[i-1][j])
			--i;
		else if(mem[i][j] == mem[i][j-1])
			--j;
	}

	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
	return 0;
}

//int go(int idx1, int idx2) {
//
//	if (idx1 >= s1.length || idx2 >= s2.length) return 0;
//	if (mem[idx1][idx2] != -1) return mem[idx1][idx2];
//
//	mem[idx1][idx2] = 0;
//
//	if(s1[idx1] == s2[idx2]) {
//		mem[idx1][idx2] = mem[idx1 - 1][idx2 - 1] + 1;
//		go(idx1 + 1, idx2 + 1);
//	}
//	else {
//		mem[idx1][idx2] = max(mem[idx-1);
//
//	}
//
//
//}

