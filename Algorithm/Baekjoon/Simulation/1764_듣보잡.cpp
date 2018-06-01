#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	set<string> h;
	vector<string> ans;

	cin >> N >> M;

	string in;
	for (int i = 1; i <= N; i++) {
		cin >> in;
		h.insert(in);
	}

	for (int i = 1; i <= M; i++) {
		cin >> in;
		if (h.count(in) > 0) ans.push_back(in);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";

	for (auto e : ans)
		cout << e << "\n";

}