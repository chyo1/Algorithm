#include <stdio.h>
int main() {
	int N, i;
	long long len = 1, len1 = 1, len2 = 1;
	scanf("%d", &N);
	if (N == 1) printf("4");
	else if (N == 2) printf("6");
	else {
		for (i = 2; i < N; i++) {
			len = len1 + len2;
			len2 = len1;
			len1 = len;
		}

		printf("%lld", 2 * (2 * len + len2));
	}
	return 0;
}