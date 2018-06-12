#include<iostream>
#include<set>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int ans = 0;
	string str;
	set<string> croatia{ "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	cin >> str;

	for(int i=0; i<str.length(); i++) {
		ans++;
		for(int len = 2; len <=3; len++) {
			if (i + len <= str.length()) {
				string sub = str.substr(i, len);
				if ( (croatia.find(sub)) != croatia.end() )
					i = i + len - 1;
			}
		}
		
	}
	cout << ans << "\n";
	return 0;

}