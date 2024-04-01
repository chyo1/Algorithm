#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	set <string> S;
	string s;

	cin >> s;
	for (int i = 1; i <= s.size(); i++) {
		for (int j = 0; j <= s.size() - i; j++) {
			S.insert(s.substr(j, i));
		}
	}
	printf("%d", S.size());
	return 0;
}