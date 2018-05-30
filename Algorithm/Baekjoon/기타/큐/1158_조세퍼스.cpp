#include <iostream>
#include <list>
using namespace std;
int main() {
	list<int> l;
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		l.push_back(i);
	}
	auto iter = l.begin();

	cout << "<";
	for (int i = 1; i <= n; i++) {

		for (int j = 1; j < m; j++) {

			if (iter == l.end()) {
				iter = l.begin();
			}
			iter++;
			if (iter == l.end()) {
				iter = l.begin();
			}
		}
		cout << *iter;
		iter = l.erase(iter);
		if (i == n)
			cout << ">" << endl;
		else
			cout << ", ";
	}


}