#include<iostream>
#include<queue>
using namespace std;

int main() {
	int N, M, temp;
	queue<int> q;
	
	cin >> N >> M;

	for (int i=1; i <= N; i++) {
		q.push(i);
	}
	cout << "<";
	int j = 1;
	while(q.size()) {
		if (j % M == 0) {
			cout << q.front();
			q.pop();
			if (q.size()) {
				cout << ", ";
			}
		}
		else {
			temp = q.front();
			q.pop();
			q.push(temp);
		}
		j++;
	}
	cout << ">\n";
	return 0;
}