#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>

using namespace std;

int main() {

	vector<char> a, b, c, d;
	vector<char>* arr[5] = { NULL, &a, &b, &c, &d };
	int twvIdx[5], dir[5];
	bool isEqual[5][2];
	const int LEFT = 6, RIGHT = 2;
	char ch;

	memset(twvIdx, 0, sizeof(twvIdx));
	memset(isEqual, false, sizeof(isEqual));

	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> ch;
			(*arr[i]).push_back(ch);
		}
	}

	int t, n, direcction;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> direcction;
		dir[n] = direcction;

		for (int j = 1; j <= 3; j++) {
			vector<char> cur = *arr[j];
			vector<char> next = *arr[j+1];
			int curRight = (twvIdx[j] + RIGHT) % 8;
			int nextLeft = (twvIdx[j+1] + LEFT) % 8;

			if (cur[curRight] != next[nextLeft]) {
				isEqual[j][1] = false;
				isEqual[j + 1][0] = false;
			}
			else {
				isEqual[j][1] = true;
				isEqual[j + 1][0] = true;
			}
		}

		int l = 1, r = 1;
		twvIdx[n] = (twvIdx[n] - dir[n] + 8) % 8;
		while (n - l > 0 || n + r < 5) {
			if (n - l > 0) {
				if (isEqual[n - l][1]) 
					dir[n-l] = 0;
				else {
					dir[n - l] = -dir[n - l + 1];
					twvIdx[n - l] = (twvIdx[n - l] - dir[n - l] + 8) % 8;
				}
				l++;
			}
			if (n + r < 5) {
				if (isEqual[n + r][0])
					dir[n + r] = 0;
				else {
					dir[n + r] = -dir[n + r - 1];
					twvIdx[n + r] = (twvIdx[n + r] - dir[n + r] + 8) % 8;
				}
				r++;
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= 4; i++) {
		vector<char> curr = *arr[i];
		if (curr[twvIdx[i]] == '1')
			ans += pow(2, i-1);
	}

	cout << ans;
}