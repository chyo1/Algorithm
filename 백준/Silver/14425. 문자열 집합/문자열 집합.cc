#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;

set <string> Set;

int main() {
	int N, M, a, cnt = 0;
	string C;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		cin >> C;
		Set.insert(C);
	}
	for (int i = 0; i < M; i++) {
		cin >> C;

		if (Set.find(C) != Set.end()) cnt++;
	}
	printf("%d", cnt);
	return 0;
}