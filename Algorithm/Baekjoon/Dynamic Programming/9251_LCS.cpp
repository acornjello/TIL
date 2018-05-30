#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string str1, str2;
	vector<vector<int>> lcs(1001, vector<int>(1001, 0));

	cin >> str1 >> str2;

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i-1] == str2[j-1])
				lcs[i][j] = lcs[i-1][j-1] + 1;
			else
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}	
	}

	cout << lcs[str1.length()][str2.length()];

	return 0;
}

/*사용된 LCS : 배열중에 수가 변하는 곳 // 대각선 & 끝나면 위로..*/