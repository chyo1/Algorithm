#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int C1[10001], C2[10001], res[10001];
char A[10001], B[10001];

int main() {

	int len, len_A, len_B, i;
	scanf("%s %s", &A, &B);

	len_A = strlen(A), len_B = strlen(B);
	reverse(A, A + len_A);
	reverse(B, B + len_B);

	for (i = 0; i < len_A; i++) C1[i] = A[i] - '0';
	for (i = 0; i < len_B; i++) C2[i] = B[i] - '0';

	len = len_A > len_B ? len_B : len_A; // short length
	for (i = 0; i < len; i++) {
		res[i] += C1[i] + C2[i];
		if (res[i] >= 10) res[i + 1]++, res[i] %= 10;
	}

	if (len_A > len_B) {
		for (i = len; i < len_A; i++) {
			res[i] += C1[i];
			if (res[i] >= 10) res[i + 1]++, res[i] %= 10;
		}
		if (res[len_A] != 0) len_A++;
		for (i = len_A - 1; i >= 0; i--) printf("%d", res[i]);
	}
	else {
		for (i = len; i < len_B; i++) {
			res[i] += C2[i];
			if (res[i] >= 10) res[i + 1]++, res[i] %= 10;
		}
		if (res[len_B] != 0) len_B++;
		for (i = len_B - 1; i >= 0; i--) printf("%d", res[i]);
	}

	return 0;
}