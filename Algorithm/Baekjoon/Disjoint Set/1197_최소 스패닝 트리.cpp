#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct edge{
	int n1, n2;
	int weight;
};
struct compare {
	bool operator() (edge& a, edge& b) {
		if (a.weight <= b.weight) {
			return false;
		}
		else {
			return true;
		}
	}
};

vector<int> p(1e4+1);
vector<int> m_rank(1e4 + 1);
priority_queue<edge, vector<edge>, compare> q;

int V, E, A, B, C;
int tot_weight = 0;

int Find(int idx) {
	if (idx == p[idx]) return idx;

	return p[idx] = Find(p[idx]);
}

void Union(edge e) {
	e.n1 = Find(e.n1);
	e.n2 = Find(e.n2);

	if (e.n1 == e.n2) return;

	if (m_rank[e.n1] > m_rank[e.n2]) swap(e.n1, e.n2);
	p[e.n1] = e.n2;
	
	tot_weight += e.weight;

	if (m_rank[e.n1] == m_rank[e.n2]) m_rank[e.n2]++;
}

int main() {
	edge e;
	cin >> V >> E;
	
	for (int i = 1; i <= V; i++) {
		p[i] = i;
	}

	for(int i=1; i<=E; i++) {
		cin >> A >> B >> C;
		e.n1 = A;
		e.n2 = B;
		e.weight = C;

		q.push(e);
	}

	while(!q.empty()) {
		e = q.top();
		Union(e);
		q.pop();
	}
	cout << tot_weight << endl;
	return 0;
}