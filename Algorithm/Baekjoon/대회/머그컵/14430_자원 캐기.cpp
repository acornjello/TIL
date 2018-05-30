#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> node(301, vector<int>(301));
int N, M;

int proc() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			node[i][j] += max(node[i - 1][j], node[i][j-1]);
		}
	}

	return node[N][M];
}
int main() {
	int tmp;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> tmp;
			node[i][j] = tmp;
		}
	}

	cout << proc() << endl;

}