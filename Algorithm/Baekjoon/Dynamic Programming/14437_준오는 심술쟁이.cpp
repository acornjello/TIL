#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define MOD 1000000007
using namespace std;
vector<vector<int>> dp(3001, vector<int>(3001, 0));
int cnt = 0;
int s;
string str;

int GO(int n, int pos) {
	if (n == 0)
		return 1;
	if (pos == str.length()) //
		return 0;
	if (dp[n][pos] != 0)
		return dp[n][pos];

	for (int i = 0; i <= min(n, 25); i++) //
		dp[n][pos] = (dp[n][pos] + GO(n - i, pos + 1)) % MOD; //

	return dp[n][pos];
}



int main() {

	cin >> s >> str;

	cout << GO(s, 0);

}