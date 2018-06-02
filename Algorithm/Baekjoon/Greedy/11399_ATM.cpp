#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, in;
	int sum = 0, ans = 0;
	vector<int> v;
	queue<int> q;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> in;
		v.push_back(in);
	}
	sort(v.begin(), v.end());

	for (auto n : v) {
		sum = sum + n;
		q.push(sum);
	}

	while (!q.empty()) {
		ans += q.front();
		q.pop();
	}

	cout << ans;
}