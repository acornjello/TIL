#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<char>>node(22, vector<char>(22));
vector<bool> alpha(22, false);
int R, C, maxLen = 0;

int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};

void Input() {
	char ch;
	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> node[i][j];
		}
	}
}

void DFS(int x, int y, int cnt) {
	if (alpha[node[y][x] - 'A'] == true) return;

	alpha[node[y][x] - 'A'] = true;

	maxLen = max(maxLen, cnt);

	for (int i = 0; i < 4; i++) {
		if (x + tx[i] >= 1 && x + tx[i] <= C && y + ty[i] >= 1 && y + ty[i] <= R)
			DFS(x+tx[i], y+ty[i], cnt+1);
	}
	
	alpha[node[y][x] - 'A'] = false;

	return;
}

int main() {

	Input();

	DFS(1, 1, 1);

	cout << maxLen << endl;

	return 0;
}
