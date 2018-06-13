// min (len, n-len);
#include<iostream>
#include<list>

using namespace std;

int main() {

	int N, M, in;
	list<int> q1, q2;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		q1.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		cin >> in;
		q2.push_back(in);
	}
	int left, right, pop;
	left = right = pop = 0;

	while (!q2.empty()) {
		int elem = q2.front();
		q2.pop_front();

		int i = 0;
		for (auto iter = q1.begin(); iter != q1.end(); iter++) {
			if (*iter == elem) {
				int qSize = q1.size();
				if (i <= (qSize / 2)) {
					left += i;
					for (int j = 0; j < i; j++) {
						q1.push_back(q1.front());
						q1.pop_front();
					}
				}
				else {
					right += qSize - i;
					for (int j = 0; j < qSize - i; j++) {
						q1.push_front(q1.back());
						q1.pop_back();
					}
				}
				q1.pop_front();
				break;
			}
			i++;
		}
	}

	cout << left + right;

	return 0;
}