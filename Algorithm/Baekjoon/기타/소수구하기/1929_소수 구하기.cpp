#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int M, N;
	
	
	cin >> M >> N;

	vector<int> v(N+1, 1);
	v[1] = 0;

	for (int i = 2; i <= sqrt(N); i++) {
		for (int j = 2; i*j <= N; j++) {
			v[i*j] = 0;
		}
	}

	for (int i = M; i <= N; ++i)
	{
		if (v[i])
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
