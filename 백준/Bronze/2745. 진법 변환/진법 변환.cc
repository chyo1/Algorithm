#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	int B, sum = 0;
	string S;
	cin >> S;
	scanf("%d", &B);
	int len = S.size();
	for (int i = len - 1; i >= 0; i--) {
		if ('A' <= S[i] && S[i] <= 'Z') {
			sum += pow(B, len - i - 1)*(S[i] - 'A' + 10);
		}
		else sum += pow(B, len - i - 1)*(S[i] - '0');
	}
	printf("%d", sum);
	return 0;
}