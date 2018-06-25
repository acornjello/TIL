#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>
#include <string>
using namespace std;

string Answer;
vector<int> sz(10001, 4);
vector<int> dp[10001];
set<int, greater<int>> palindrome;


int solve(int curr, int cnt) {
	if (sz[curr] != 4) return sz[curr];
	if (cnt > 3) return 4;

	for (auto p : palindrome) {
		int prev = curr - p;
		if (prev < 0) continue;
		if (solve(prev, cnt + 1) + 1 < sz[curr]) {
			dp[curr].clear();
			dp[curr].insert(dp[curr].begin(), dp[prev].begin(), dp[prev].end());
			dp[curr].push_back(p);
			sz[curr] = dp[curr].size();
		}
	}
	return sz[curr] = dp[curr].size();
}
int main()
{
	int T, test_case;

	for (int i = 1; i <= 10000; i++) {
		string str = to_string(i);

		int len = str.length();
		string left = str.substr(0, len / 2);
		string right = str.substr(len / 2 + (len % 2), len / 2);
		reverse(right.begin(), right.end());
		if (left == right) {
			palindrome.insert(i);
			dp[i].push_back(i);
			sz[i] = 1;
		}
	}

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = "";
		int N;
		cin >> N;

		int sz = solve(N, 0);
		sz = sz > 3 ? 0 : sz;
		Answer += to_string(sz);
		for (int j = sz - 1; j >= 0; j--) {
			Answer += " " + to_string(dp[N][j]);
		}
		
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}