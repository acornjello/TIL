#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int CustomHash(const char *str) {
	unsigned long hash = 5381;
	int c;
	while (c = *str++)
		hash = ((hash << 5) + hash) + c;
	return hash & 0x7FFFFFFF;
}

int main() {

