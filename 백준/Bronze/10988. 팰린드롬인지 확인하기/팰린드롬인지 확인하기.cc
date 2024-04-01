#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	int len = S.length() - 1;
	for (int i = 0; i <= len / 2; i++) {
		if (S[i] != S[len - i]) {
			printf("0");
			return 0;
		}
	}
	printf("1");
	return 0;
}