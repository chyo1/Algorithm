#include <stdio.h>
int main() {
	int A, B, C, mul, i, cnt[10] = { 0, };
	scanf("%d%d%d", &A, &B, &C);
	mul = A * B * C;
	while (mul) {
		cnt[mul % 10]++;
		mul /= 10;
	}
	for (i = 0; i < 10; i++) printf("%d\n", cnt[i]);
}