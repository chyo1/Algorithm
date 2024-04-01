#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string S;
	int cnt[2] = { 0, };

	cin >> S;

	char now = '2';
	for (int i = 0; i < S.size(); i++) {
		if (now != S[i]) {
			cnt[S[i] - '0']++;
			now = S[i];
		}
	}

	cnt[0] < cnt[1] ? printf("%d", cnt[0]) : printf("%d", cnt[1]);

	return 0;
}