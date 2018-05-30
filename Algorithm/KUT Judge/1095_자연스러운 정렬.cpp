#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct file {
	string fname;
	int idx;
};
bool compare(string left, string right) {
	
	int lIdx = 0;
	int rIdx = 0;
	while (lIdx < left.length() && rIdx < right.length()) {
		
		long long lNum = INT64_MAX;
		long long rNum = INT64_MAX;
		
		while (left[lIdx] >= '0' && left[lIdx] <= '9') {
			if (lNum == INT64_MAX) lNum = 0;
			lNum *= (long long)10;
			lNum += (long long)(left[lIdx] - '0');
			lIdx++;
		}
		while (right[rIdx] >= '0' && right[rIdx] <= '9') {
			if (rNum == INT64_MAX) rNum = 0;
			rNum *= (long long) 10;
			rNum += (long long) (right[rIdx] -'0');
			rIdx++;
		}
		
		if (lNum != INT64_MAX || rNum != INT64_MAX) {
			if (lNum == rNum)
				continue;
			
			return lNum < rNum;
		}

		if (left[lIdx] == right[rIdx]) {
			lIdx++;
			rIdx++;
			continue;
		}

		return left[lIdx] < right[rIdx];
	}

	return left.length() - lIdx < right.length() - rIdx;
}
int main() {
	int N;
	vector<string> in;

	cin >> N;

	in.resize(N, "");
	
	for (int i = 0; i < N; i++) {
		cin >> in[i];
	}


	sort(in.begin(), in.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << in[i] << endl;
	}



	return 0;
}