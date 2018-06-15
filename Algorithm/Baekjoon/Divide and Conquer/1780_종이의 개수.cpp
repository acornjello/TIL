#include<iostream>

using namespace std;

int N;
int paper[2500][2500];
int ans[3];

void go(int y, int x, int sz) {
	bool check = true;
	
	for (int i = y; i < y+sz; i++) {
		if (!check) break;
		for (int j = x; j < x+sz; j++) {
			if (paper[y][x] != paper[i][j]) {
				check = false;
				break;
			}
		}
	}

	if(check) {
		ans[paper[y][x] + 1]++;
	}
	else {
		int nextSz = sz / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				go(y + nextSz*i, x + nextSz*j, nextSz);
			}
		}
	}

}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];

	go(0, 0, N);

	for (int i = 0; i < 3; i++)
		cout << ans[i] << "\n";
	
	return 0;
}