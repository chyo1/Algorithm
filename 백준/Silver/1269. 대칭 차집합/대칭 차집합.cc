#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	int a, b, cnt = 0;
	set <string> A, B;
	string s;

	scanf("%d %d", &a, &b);
	for (int i = 0; i < a; i++) {
		cin >> s;
		A.insert(s);
	}
	for (int i = 0; i < b; i++) {
		cin >> s;
		B.insert(s);
	}

	for (auto b = B.begin(); b!=B.end(); b++) {
		if (A.find(*b) == A.end()) cnt++;
	}
	for (auto a = A.begin(); a != A.end(); a++) {
		if (B.find(*a) == B.end()) cnt++;
	}

	printf("%d", cnt);
	return 0;
}