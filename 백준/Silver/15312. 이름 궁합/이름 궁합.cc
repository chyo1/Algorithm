#include <stdio.h>
#include <string.h>
int main() {
	char cA[2001], cB[2001];
	int A[2000], B[2000], sum[4002];
	int len, i, j;
	int al[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
	scanf("%s", &cA);
	scanf("%s", &cB);

	len = strlen(cA);
	for (i = 0; i <= len; i++) A[i] = al[cA[i] - 'A'], B[i] = al[cB[i] - 'A'];

	for (i = 0; i < len; i++) {
		sum[2 * i] = (A[i] + B[i]) % 10;
		sum[2 * i + 1] = (A[i + 1] + B[i]) % 10;
	}
	len = 2 * len - 2;
	while (len >= 2) {
		for (j = 0; j < len; j++) {
			sum[j] = (sum[j] + sum[j + 1]) % 10;
		}
		len--;
	}
	printf("%d%d", sum[0], sum[1]);
	return 0;
}