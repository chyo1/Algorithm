#include <stdio.h>
int main() {
	int X, sum = 0, i = 1;
	scanf("%d", &X);

	while (sum + i < X) {
		sum += i++;
	}
	if (i % 2) printf("%d/%d", sum + i - X + 1, X - sum); // 홀수
	else printf("%d/%d", X - sum, sum + i - X + 1);
	return 0;
}