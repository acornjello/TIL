#include<iostream>
#include<vector>

using namespace std;

int n, m, c, a, b;
vector<int> p(1e6 + 1, -1);
vector<int> m_rank(1e6 + 1, -1);

int Find(int idx) {
	if (idx == p[idx]) return idx;

	return p[idx] = Find(p[idx]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return;
	if (m_rank[a] > m_rank[b]) swap(a, b);
	p[a] = b;
	if (m_rank[a] == m_rank[b]) ++m_rank[b];
}
// 초기화 후, 연산 1. 0 이면 Union(a, b) 2. 1이면 Find(a)==Find(b)? "YES" : "NO"
int main() {

	scanf("%d%d", &n, &m);

	for (int i = 0; i <= n; i++) {
		p[i] = i;
	}

	while (m--) {
		scanf("%d%d%d", &c, &a, &b);

		if (c == 0) {
			Union(a, b);
		}
		else {
			if (Find(a) == Find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}