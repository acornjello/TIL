#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

#define MAX_LEN 100000000

struct pos {
	int r, c;
};
int N, M, ans;
int city[51][51], minDist[51];
bool checked[51];
vector<pos> house, store;
vector<stack<int>> v;
stack<int> temp;

int calDistance(int r1, int c1, int r2, int c2) {
	return abs(r1 - r2) + abs(c1 - c2);
}

void go(int idx, int cnt) {
	if (idx > store.size()) return;
	if (cnt == M) {
		for (int i = 0; i < house.size(); i++) {
			minDist[i] = MAX_LEN;
		}
		
		for (int i = 0; i < store.size(); i++) {
			if (checked[i]) {
				for (int j=0; j<house.size(); j++) {
					minDist[j] = min(minDist[j], calDistance(house[j].r, house[j].c, store[i].r, store[i].c));
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			sum += minDist[i];
		}
		ans = min(ans, sum);
		return;
	}

	for(int i=idx+1; i<store.size(); i++) {
		checked[i] = true;
		go(i, cnt + 1);
		checked[i] = false;
	}
}

void go2(int idx, int M) {
	if (idx > store.size()) return;

	if (M == 0) {
		v.push_back(temp);
		return;
	}

	temp.push(idx);
	go2(idx + 1, M - 1);
	temp.pop();
	go2(idx + 1, M);
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			switch (city[i][j]) {
			case 1: house.push_back({ i, j }); break;
			case 2: store.push_back({ i, j }); break;
			default:
				break;
			}
		}
	}

	ans = MAX_LEN;

	//go(0, 0);
	go2(0, M);



	for (int i = 0; i < v.size(); i++) {
		stack<int> st = v[i];

		for (int i = 0; i < house.size(); i++) {
			minDist[i] = MAX_LEN;
		}

		while (!st.empty()) {
			int idx = st.top();
			for (int j = 0; j < house.size(); j++) {
				minDist[j] = min(minDist[j], calDistance(house[j].r, house[j].c, store[idx].r, store[idx].c));
			}
			st.pop();
		}

		int sum = 0;

		for (int j = 0; j < house.size(); j++) {
			sum += minDist[j];
		}
		ans = min(ans, sum);
	}

	cout << ans << "\n";

	return 0;
}
