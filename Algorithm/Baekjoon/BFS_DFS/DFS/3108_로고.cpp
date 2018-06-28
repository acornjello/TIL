#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

bool visited[1000];
int N;

struct info{
	int x1, y1;
	int x2, y2;
};

vector<info> square(1000);

void dfs(int idx) {
	cout << idx << " ";
	visited[idx] = true;

	int y1 = square[idx].y1;
	int x1 = square[idx].x1;
	int y2 = square[idx].y2;
	int x2 = square[idx].x2;

	for (int i = idx+1; i < N; i++) {
		int ny1 = square[i].y1;
		int nx1 = square[i].x1;
		int ny2 = square[i].y2;
		int nx2 = square[i].x2;

		if (nx1 > x1 && nx2 < x2 && ny1 > y1 && ny2 < y2) continue;
		if (nx1 > x2 || nx2 < x1 || ny1 > y2 || ny2 < y1) continue;
		if(!visited[i]) dfs(i);
	}
	
}

int main() {
	
	cin >> N;
	vector<info> square;

	for (int i = 0; i < N; i++) {
		info in;
		cin >> in.x1 >> in.y1 >> in.x2 >> in.y2;
		square.push_back(in);
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
		
	}

	int i = 0;

	for (; i < N; i++) {
		int y1 = square[i].y1;
		int x1 = square[i].x1;
		int y2 = square[i].y2;
		int x2 = square[i].x2;

		if ((x1 <= 0 && x2 >= 0 && (y1 == 0 || y2 == 0))
			|| y1 <= 0 && y2 >= 0 && (x1 == 0 || x2 == 0)) {
			ans--;
			break;
		}
	}
	cout << ans;

	return 0;
}