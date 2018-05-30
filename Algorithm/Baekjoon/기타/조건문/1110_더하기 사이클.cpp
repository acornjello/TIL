/*#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
using namespace std;

int main() {
string str;
cin >> str;

vector<int> v(5, 0);
v[1] = -1;
v[4] = 1;
for (int i = 0; i < str.length(); i++) {
switch (str[i]) {
case 'A':
swap(v[1], v[2]); break;
case 'B':
swap(v[1], v[3]); break;
case 'C':
swap(v[1], v[4]); break;
case 'D':
swap(v[2], v[3]); break;
case 'E':
swap(v[2], v[4]); break;
case 'F':
swap(v[3], v[4]); break;
default: break;
}
}
for (int i = 1; i < v.size(); i++) {
if (v[i] == -1)	cout << i << endl;
}
for (int i = 1; i < v.size(); i++) {
if (v[i] == 1)	cout << i << endl;
}
}
*/

/* 1546
#include<iostream>
#include <vector>
#include<cmath>
using namespace std;
int main() {
double n, max = 0.0;
double round, sum = 0.0;
double result;

cin >> n;
vector<double> score(n, 0.0);

for (int i = 0; i < n; i++) {
cin >> score[i];
if (max < score[i]) max = score[i];
}
for (int i = 0; i < n; i++) {
score[i] = (score[i] / max) * 100;
sum += score[i];
}

round = (sum / n) * 1000 % 10;
if (round >= 5)
result = (int)((sum / n) * 1000 + 10 - round)/1e3;
else
result = (int)((sum / n) * 1000 - round) / 1e3;
cout << result << endl;
return 0;
}
*/
/* 4344
#include<iostream>
#include <vector>
using namespace std;
int main() {
int T, n, cnt = 0;
double sum = 0.0, avg;
cin >> T;

for (int i = 0; i < T; i++) {
cin >> n;
vector<double> score(n, 0);
for (int j = 0; j < n; j++) {
cin >> score[j];
sum += score[j];
}
avg = sum / n;
for (int j = 0; j < n; j++) {
if (score[j] >= avg) cnt++;
}
cout << cnt / n * 100 << "%" << endl;
}
return 0;
}

}
*/
#include <iostream>
using namespace std;
int main() {
	int cnt = 1;
	int n, ten, one, result, newnum;

	cin >> n;

	newnum = n;

	ten = n / 10;
	one = n % 10;
	result = ten + one;

	ten = one;
	one = result % 10;
	newnum = ten * 10 + one;

	while (n != newnum) {
		ten = newnum / 10;
		one = newnum % 10;
		result = ten + one;

		ten = one;
		one = result % 10;
		newnum = ten * 10 + one;

		cnt++;
	}


	cout << cnt << endl;
	return 0;
}