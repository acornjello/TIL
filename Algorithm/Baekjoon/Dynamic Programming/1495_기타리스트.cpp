#include<iostream>
#include<algorithm>

using namespace std;

int N, S, M, ans = -1;
int v[101];
bool mem[101][10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> S >> M;

	for (int i = 1; i <= N; i++)
		cin >> v[i];

	mem[0][S] = true;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (!mem[i - 1][j]) continue;
			if (j - v[i] >= 0) mem[i][j - v[i]] = true;
			if (j + v[i] <= M) mem[i][j + v[i]] = true;
			if (i == N) {
				ans = max(ans, (j - v[i] >= 0) ? j - v[i] : -1);
				ans = max(ans, (j + v[i] <= M) ? j + v[i] : -1);
			}
		}
	}
	
	cout << ans;

}