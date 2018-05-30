#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int N, trsv = 0, length = 0;
	char maze[100][100];

	cin >> N;

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			cin >> maze[r][c];
		}
	}


	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N-1; ++c) {
			if (maze[r][c] == '.' && maze[r][c + 1] == '.') {
				++trsv;
				c = (c > N - 4) ? c : c + 2;
				while (maze[r][c] != 'X' && c < N - 2) {
					++c;
				}
			}
		}
	}


	for (int c = 0; c < N; ++c) {
		for (int r = 0; r < N - 1; ++r) {
			if (maze[r][c] == '.' && maze[r + 1][c] == '.') {
				++length;
				r = (r > N - 4) ? r : r + 2;
				while (maze[r][c] != 'X' && r < N - 2) {
					++r;
				}
			}
		}
	}

	cout << trsv << " " << length << endl;

	return 0;
}