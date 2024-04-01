#include <stdio.h>

int main() {
	int sum1 = 0, sum2 = 0, n;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &n);
		sum1 += n;
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &n);
		sum2 += n;
	}
	if (sum1 > sum2) printf("%d", sum1);
	else printf("%d", sum2);
	return 0;
}