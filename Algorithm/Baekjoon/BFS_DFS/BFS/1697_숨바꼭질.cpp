#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, K;
vector<int> visited(100001, 0);
queue<int> q;

int BFS() {
	while (!q.empty()) {
		if (q.front() == K) break;
		
		if (q.front() - 1 >= 0 && visited[q.front() - 1]==0) {
			q.push(q.front() - 1);
			visited[q.front() - 1] = visited[q.front()] + 1;
		}
		if (q.front() + 1 <= 1e5 && visited[q.front() + 1]==0) {
			q.push(q.front() + 1);
			visited[q.front() + 1] = visited[q.front()] + 1;
		}
		if (q.front() * 2 <= 1e5 && visited[2*q.front()]==0) {
			q.push(q.front() * 2);
				
			visited[q.front() * 2] = visited[q.front()] + 1;
		}
		
		q.pop();
	}
	return visited[q.front()]-1;
}
int main() {

	cin >> N >> K;

	q.push(N);
	visited[q.front()] = 1;
	cout << BFS() << endl;
	return 0;
}