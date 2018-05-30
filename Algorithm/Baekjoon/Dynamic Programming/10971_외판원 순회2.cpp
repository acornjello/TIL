#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX_VAL 1*1e6
int w[11][11], mem[11][1 << 11];
int N, start;

int DP(int src, int visit) {
	if (visit == (1 << N) - 1) {
		if (w[src][start] == 0)
			return MAX_VAL;
		else
			return w[src][start];
	}
	if (mem[src][visit] != -1) return mem[src][visit];

	for (int i = 1; i <= N; i++) {
		bool visited = (visit & 1 << (i - 1));
		int newVisit = visit | (1 << (i - 1));
		if (!visited && w[src][i] != 0)
			mem[src][visit] = min(mem[src][visit], w[src][i] + DP(i, newVisit));
	}
	return mem[src][visit];
}

int main() {
	int ans = MAX_VAL;

	cin >> N;

	memset(mem, -1, sizeof(mem));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &w[i][j]);

	start = 1;
	ans = min(ans, DP(1, 1));

	printf("%d\n", ans);

	return 0;
}