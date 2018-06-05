#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int N;
char v[64][64];
int dx[4] = { 0, 1, 0, 1}, dy[4] = { 0, 0, 1, 1 };
vector<char> quad;
void go(int x, int y, int sz) {
	bool isEqual = true;
	for (int i = y; i < y+sz; i++) {
		for (int j = x; j < x+sz; j++) {
			if (v[y][x] != v[i][j]) {
				quad.push_back('(');
				for (int k = 0; k < 4; k++) {
					go(x + (dx[k] * (sz / 2)), y + (dy[k] * (sz / 2)), sz / 2);
				}
				quad.push_back(')');
				return;
			}
		}
	}

	quad.push_back(v[y][x]);
	
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	
	char c;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}


	go(0, 0, N);

	for (auto c : quad)
		cout << c;

}