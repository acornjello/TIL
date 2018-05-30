#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Time {
	int start;
	int end;
};

bool compareTime(Time a, Time b) {
	if (a.end == b.end)
		return a.start < b.start;
	return a.end < b.end;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, start, end, last, ans;
	vector<Time> conferences;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		conferences.push_back({ start, end });
	}

	sort(conferences.begin(), conferences.end(), compareTime);
	
	last = 0;ans = 0;
	
	for (int i = 0; i < N; i++) {
		if (conferences[i].start >= last) {
			last = conferences[i].end;
			ans++;
		}
	}
	cout << ans << "\n";
}