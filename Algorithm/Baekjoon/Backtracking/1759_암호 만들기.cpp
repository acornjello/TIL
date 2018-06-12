#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int L, C;
vector<char> v, store;

bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return 1;
	else
		return 0;
}
void go(int idx, int len, int vowel, int cons) {
	if (len == L && vowel >= 1 && cons >= 2) {
		for (auto e : store)
			cout << e;
		cout << "\n";
		return;
	}
	if (idx >= C) return;
	

	store.push_back(v[idx]);
	int temp = isVowel(v[idx]);
	go(idx + 1, len + 1, vowel + temp, cons + !temp);
	store.pop_back();
	go(idx + 1, len, vowel, cons);

}

int main() {
	char c;
	cin >> L >> C;
	
	for (int i = 0; i < C; i++) {
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	go(0, 0, 0, 0);

	return 0;
}