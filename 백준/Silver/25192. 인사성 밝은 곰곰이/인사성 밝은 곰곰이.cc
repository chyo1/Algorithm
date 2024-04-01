#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;

set <string> name;

int main() {
	int N, cnt = 0;
	string S;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> S;
		if (S == "ENTER") {
			cnt += name.size();
			name.clear();
		}
		else name.insert(S);
	}
	cnt += name.size();

	printf("%d", cnt);
	return 0;
}