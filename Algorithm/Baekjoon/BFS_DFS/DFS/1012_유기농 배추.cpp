#include<iostream>
#include<vector>

using namespace std;

int N, M, K;
vector<vector<int>> node(50, vector<int>(50));
vector<vector<bool>> visited(50, vector<bool>(50));
int bug = 0;


void DFS(int y, int x) {
	node[y][x] = 0;
	if (x + 1 < M && node[y][x + 1] == 1) {
		DFS(y, x + 1);
	}
	if (x - 1 >= 0 && node[y][x - 1] == 1) {
		DFS(y, x - 1);
	}
	if (y + 1 < N && node[y + 1][x] == 1) {
		DFS(y + 1, x);
	}
	if (y - 1 >= 0 && node[y - 1][x] == 1) {
		DFS(y - 1, x);
	}
}


int main() {
	int T, cnt;
	int x, y;

	cin >> T;

	while (T--) {
		cnt = 0;

		cin >> M >> N >> K;


		while (K--) {
			cin >> x >> y;
			node[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (node[i][j] == 1) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;


}
