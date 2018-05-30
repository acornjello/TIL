#include<iostream>
#include<vector>
#include<queue>
#include <functional>
#include<algorithm>

using namespace std;
#define M 1e8+1
struct info {
	int idx;
	int cost;
};
bool operator <(const info &a, const info &b) {
	return (a.cost < b.cost);
}
bool operator >(const info &a, const info &b) {
	return (a.cost > b.cost);
}

int n, m, s, e, c;
vector<bool> visited(1001, false);
vector<int> ansList[1001];
vector<int> ans(1001, M);
vector<info> cost[1001];

void solve2() {
	priority_queue<info, vector<info>, greater<info>> q;
	q.push({ s, 0 });
	ans[s] = 0;
	ansList[s].push_back(s);

	while (!q.empty()) {
		info curr = q.top();
		q.pop();

		for (info next : cost[curr.idx]) {
			if (curr.cost + next.cost < ans[next.idx]) {
				ans[next.idx] = curr.cost + next.cost;
				ansList[next.idx].clear();
				for (auto e : ansList[curr.idx]) {
					ansList[next.idx].push_back(e);
				}
				ansList[next.idx].push_back(next.idx);
				q.push({ next.idx, ans[next.idx] });
			}
		}
	}

	cout << ans[e] << "\n";
	cout << ansList[e].size() << "\n";
	for (auto elem : ansList[e]) {
		cout << elem;
		if (elem != ansList[e].back()) cout << " ";
	}

}

int main()
{

	cin >> n;
	cin >> m;

	for (int i = 1; i <= m; ++i) {
		cin >> s >> e >> c;
		info t = { e, c };
		cost[s].push_back(t);
	}
	cin >> s >> e;
	
	solve2();

	return 0;
}