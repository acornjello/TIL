#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, m, key;
	vector<int> arr;

	cin >> n;
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	cin >> m;

	sort(arr.begin(), arr.end());

	while (m--) {
		scanf("%d", &key);

		int left = 1, right = n;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (arr[mid] > key) {
				right = mid - 1;
			}
			else if (arr[mid] < key) {
				left = mid + 1;
			}
			else {
				printf("1\n");
				break;
			}
		}
		if (right < left) printf("0\n");
	}
	return 0;
}
