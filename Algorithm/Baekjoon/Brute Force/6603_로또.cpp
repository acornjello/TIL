#include<cstdio>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int>> ans;
vector<int> nums, temp;
void go(vector<int>& temp, int idx) {
	if (temp.size() == 6) {
		ans.push_back(temp); return;
	}
	if (idx >= (int) nums.size()) return;
	
	temp.push_back(nums[idx]);
	go(temp, idx + 1);
	temp.pop_back();
	go(temp, idx + 1);
}

int main() {

	int k;
	
	while (true) {
		scanf_s("%d", &k);
		if (k == 0) break;
		
		int a;
		nums.clear();
		ans.clear();
		temp.clear();


		for (int i = 0; i < k; i++) {
			scanf_s("%d", &a);
			nums.push_back(a);
		}

		go(temp, 0);

		for (auto v : ans) {
			for (auto e : v) {
				printf("%d ", e);
			}
			printf("\b\n");
		}
		printf("\n");
		
	}



	return 0;
}