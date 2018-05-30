#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Meeting {
	int timeStart;
	int timeEnd;
};
bool compareMeeting(Meeting a, Meeting b) { 
	return a.timeEnd < a.timeEnd;
}
int main() {
	

	int N, cnt = 0;
	vector<Meeting> timeMeeting;
	vector<Meeting> result;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int timeStart, timeEnd;
		scanf("%d %d", &timeStart, &timeEnd);
		timeMeeting.push_back({ timeStart, timeEnd });
	}

	int start, end;
	start = timeMeeting[0].timeStart;
	end = timeMeeting[0].timeEnd;

	sort(timeMeeting.begin(), timeMeeting.end());

	for (auto tm : timeMeeting) {
		if (end <= tm.timeStart) {
			cnt++;
			end = tm.timeEnd;
		}
	}

	printf("%d\n", end);


	return 0;
}