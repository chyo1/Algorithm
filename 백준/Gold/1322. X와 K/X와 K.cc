#include <stdio.h>
#include <math.h>
int main() {
	int X, K, lenk = 0, lenx = 0, now = 0;
	int binK[100] = { 0, }, binX[100] = { 0, };
	unsigned long long Y = 0;

	scanf("%d %d", &X, &K);

	// X, K 2진수 변환
	while (K > 0) {
		binK[lenk++] = K % 2;
		K /= 2;
	}

	while (X > 0) {
		binX[lenx++] = X % 2;
		X /= 2;
	}

	for (int i = 0;; i++) {
		if (binX[i] == 0 && binK[now++] == 1)
			Y += ((long long)1 << i);
		if (now > lenk) break;
	}

	printf("%llu", Y);

	return 0;
}