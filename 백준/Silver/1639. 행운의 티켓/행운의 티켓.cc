#include <stdio.h>

char s[51];
bool Is_Lucky(int start, int end) {
	int sum1 = 0, sum2 = 0, mid = (start + end) / 2;

	for (int i = start; i < mid; i++) sum1 += s[i] - '0';
	for (int i = mid; i < end; i++) sum2 += s[i] - '0';

	if (sum1 == sum2) return true;
	return false;
}
int main() {
	int len = 0;
	scanf("%s", s);

	while (s[len++] != NULL);
	for (int i = len - 1; i >= 0; i--) {
		if (i & 1) continue;
		for (int j = 0; j < len - i; j++) {
			if (Is_Lucky(j, j + i)) {
				printf("%d", i);
				return 0;
			}
		}
	}
	return 0;
}