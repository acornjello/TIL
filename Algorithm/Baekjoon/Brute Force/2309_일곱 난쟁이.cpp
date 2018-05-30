#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> v, temp;
vector<vector<int>> ans;

bool process(int idx, int sz) {
	
	if (sz == 7) {
		int sum = 0;
		for (int i = 0; i < temp.size(); i++) {
			sum += temp[i];
		}

		if (sum == 100) {
			sort(temp.begin(), temp.end());
			for (auto e : temp)
				cout << e << "\n";
			return true;
		}
		return false;
	}
	if (idx >= v.size()) return false;

	temp.push_back(v[idx]);
	if (process(idx + 1, sz + 1)) return true;
	temp.pop_back();
	if (process(idx + 1, sz)) return true;

	return false;
}

int main() {
	v.resize(9);

	for (int i = 0; i < 9; i++)
		cin >> v[i];

	process(0, 0);

	return 0;
}