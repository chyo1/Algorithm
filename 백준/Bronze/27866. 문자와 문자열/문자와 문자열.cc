#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
	string S;
	int loc;
	cin >> S;
	scanf("%d", &loc);
	cout << S[loc - 1];

	return 0;
}