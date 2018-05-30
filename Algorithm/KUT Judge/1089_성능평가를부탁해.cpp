#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct algoData {
	int min_lost_dist = 50;
	int lost_num = 0;

};

int main() {

	int K, N;

	vector<algoData> algo(100001);
	vector<int> answerSet(51, -1);
	vector<vector<int>> resultSet(100001, vector<int>(51, -1));



	cin >> K >> N;


	for (int i = 0; i < K; i++) {
		cin >> answerSet[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cin >> resultSet[i][j];

			if ( (j + algo[i].lost_num) <= K ) {
				if ( resultSet[i][j] != answerSet[j + algo[i].lost_num] ) {
					algo[i].lost_num++;
					algo[i].min_lost_dist = min( algo[i].min_lost_dist, answerSet[j] );
				}
			}
			else {
				algo[i].lost_num++;
			}

		}
	}

	int best = 0;


	for (int i = 0; i < N; i++) {
		if (algo[i].lost_num < algo[best].lost_num) {
			best = i;
			continue;
		}
		else if (algo[i].lost_num == algo[best].lost_num) {
			if (algo[i].min_lost_dist < algo[best].min_lost_dist) {
				best = i;
			}
		}
	}

	cout << best << endl;

	return 0;
}