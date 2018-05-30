#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> node(101, vector<int>(101));
vector<int> area(10000, 0);
int M, N, K;
int field = 0;


void Input() {
	int x1, y1, x2, y2;
	cin >> M >> N >> K;	// 세로 가로 좌표
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				node[k][j] = 1;
			}
		}
	}
}
void DFS(int x, int y) {
	node[y][x] = 1;
	area[field]++;
	if (x - 1 >= 0 && node[y][x-1] == 0) {
		DFS(x - 1, y);
	}
	if (y - 1 >= 0 && node[y-1][x] == 0) {
		DFS(x, y - 1);
	}
	if (x + 1 < N && node[y][x+1] == 0) {
		DFS(x + 1, y);
	}
	if (y + 1 < M && node[y+1][x] == 0) {
		DFS(x, y + 1);
	}

}
int main() {
	Input();


	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (node[i][j] == 0) {
				field++;
				DFS(j, i);
			}
		}
	}

	
	cout << field << endl;
	sort(area.begin() + 1, area.begin() + field + 1);
	for (int i = 1; i <= field; i++) {
		cout << area[i] << " ";
	}

	return 0;
}