#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	int T, N, M, prior;

	cin >> T;
	while (T--) {
		int cnt = 0;
		queue<int> q;
		queue<int> pos;
		vector<int> prior_v;

		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> prior;

			q.push(prior);
			pos.push(i);
			prior_v.push_back(prior);
		}
		sort(prior_v.begin(), prior_v.end());

		while(true) {
			if (q.front() != *(prior_v.end() - 1)) {
				q.push(q.front());
				q.pop();

				pos.push(pos.front());
				pos.pop();
			}
			else {
				cnt++;
				if (pos.front() == M) {
					printf("%d\n",cnt);
					cnt = 0;
					prior_v.clear();
					break;
				}
				else {
					q.pop();
					pos.pop();
					prior_v.erase(prior_v.end() - 1);
				}
			}
		}

	}
	return 0;
}

