#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int team[100001];
int T, n, student[100001], numOfteam;
int visited[100001];
int finish[100001];
void cycle(int v, int p) {
	numOfteam++;
	if (v == p) {
		return;
	}
	cycle(team[v], p);
}
void dfs(int v) {
	visited[v] = true;
	if (!visited[student[v]]) {
		team[student[v]] = v;
		dfs(student[v]);
	}
	else if (!finish[student[v]]) { 
		cycle(v, student[v]);
	}
	finish[v] = true;
}
int main() {
	cin >> T;
	while (T--) {
		memset(team, -1, sizeof(team));
		memset(visited, 0, sizeof(visited));
		memset(finish, 0, sizeof(finish));

		numOfteam = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> student[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		cout << n - numOfteam;
	}
	return 0;
}














//
//#include<iostream>
//#include<string.h>
//#include<algorithm>
//#include<set>
//#include<vector>
//
//using namespace std;
//int T, N;
//int students[100001];
//vector<bool> checked, team;
//set<int> circulation;
//
// 마지막 애로 돌릴 때 사이클이 돌려지느냐, 저장해놔야함...
//
//void dfs(int i, int firstNum) {
//	if (team[i]) return;
//
//	checked[i] = true;
//
//	if (firstNum != -1) {
//		circulation.insert(i);
//		team[i] = true;
//		if (firstNum == students[i]) return;
//
//		dfs(students[i], firstNum);
//		return;
//	}
//
//	if (checked[students[i]])
//		dfs(students[i], students[i]);
//	else
//		dfs(students[i], -1);
//
//	return;
//}
//
//int main() {
//
//	cin >> T;
//
//	while (T--) {
//		cin >> N;
//		for (int i = 1; i <= N; ++i)
//			cin >> students[i];
//
//		checked = vector<bool> (N+1, false);
//		team = vector<bool>(N + 1, false);
//		circulation.clear();
//
//		for (int i = 1; i <= N; ++i)
//			if( !checked[i] )
//				dfs(i, -1);
//
//		cout << N - circulation.size() << "\n";
//	}
//
//	return 0;
//}