#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string.h>

using namespace std;

int Answer;
int N, K;
bool checked[200000];
vector<int> players;

void solve(int curr, vector<int>& temp)
{
	Answer++;
	int max_ability = players[0];

	cout << curr << " ";
	checked[0] = true;

	for (auto next : players) {
		if (!checked[next])
		{
			if (players[next] - max_ability > K) {
				max_ability = players[next];
				checked[next] = true;
			}
			else {
				//temp.era
				temp.push_back(next);
			}
		}
	}

	for (int next = curr + 1; next < N; next++) 
	{
		if (!checked[next]) 
		{
			if(players[next]- max_ability > K) {
				max_ability = players[next];
				checked[next] = true;
			}
			else {
				temp.push_back(next);
			}
		}
		
	}

	
}

int main(int argc, char** argv)
{

	players.push_back(1);
	players.push_back(1);
	players.push_back(3);
	players.push_back(1);

	for (auto iter = players.begin(); iter != players.end();) {
		if (*iter == 3) {
			iter = players.erase(iter);
		}
		else {
			iter++;
		}
		
	}
	/*
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////

		cin >> N >> K;
		players.resize(N);
		memset(checked, false, sizeof(checked));
		
		for (int i = 0; i < N; i++) 
		{
			cin >> players[i];
		}

		sort(players.begin(), players.end());

		solve(0, players);

		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}
	*/
	return 0;//Your program should return 0 on normal termination.
}


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Answer, N, K;
vector<int> players;
bool checked[200000];
void solve(int curr, vector<int>& temp) {

	for (int next = curr + 1; next < N; next++) {
		if (players[next] - players[curr]> K) {
			temp.push_back(next);
			solve(next, temp);
			temp.pop_back();
		}
	}

}

//void solve(vector<int>& players)
//{
//	int max_ability = players[0];
//	players.erase(players.begin());
//	Answer++;
//
//	if (players.empty()) return;
//	vector<int> temp;
//	for (auto iter = players.begin(); iter != players.end();) 
//	{
//		int next = *iter;
//
//		if (next - max_ability > K) 
//		{
//			max_ability = next;
//			iter = players.erase(iter);
//		}
//		else 
//		{
//			iter++;
//		}
//	}
//	if (!players.empty()) 
//	{
//		solve(players);
//	}
//
//}

int main(int argc, char** argv)
{
	setbuf(stdout, NULL);

	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////

		vector<int> players;
		scanf("%d %d\n", &N, &K);

		players.resize(N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &players[i]);
		}

		sort(players.begin(), players.end());

		solve(players);
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}