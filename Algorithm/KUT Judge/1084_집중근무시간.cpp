#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct interval {
	int sTime;
	int eTime;
};
bool compareInterval(interval a, interval b) { return a.sTime < b.sTime; };
int main() {


	int T;

	cin >> T;

	for (int t = 0; t<T; t++) {
		vector<interval> timePatrol;
		vector<interval> timeAttention;
		int N, sTime, eTime;

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> sTime >> eTime;
			timePatrol.push_back({ sTime, eTime });
		}

		sort(timePatrol.begin(), timePatrol.end(), compareInterval);

		timeAttention.push_back({ timePatrol[0].sTime, timePatrol[0].eTime });

		for (auto tp : timePatrol) {

			int sTime = timeAttention.back().sTime;
			int eTime = timeAttention.back().eTime;

			if (tp.sTime > eTime) {
				timeAttention.push_back({ tp.sTime, tp.eTime });
			}
			else {
				timeAttention.back().sTime = min(sTime, tp.sTime);
				timeAttention.back().eTime = max(eTime, tp.eTime);
			}
		}
		cout << timeAttention.size() << endl;
		for (int i = 0; i<timeAttention.size(); i++) {
			cout << timeAttention[i].sTime << " " << timeAttention[i].eTime;
			if (i < timeAttention.size() - 1) cout << " ";
		}
		cout << endl;
	}
	return 0;
}