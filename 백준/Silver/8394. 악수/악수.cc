#include <stdio.h>
int N[10000001];
int main() {
	int n;
	int n1 = 1, n2 = 2, n3 = 3, tmp;
	N[1] = 1, N[2] = 2, N[3] = 3;
	scanf("%d", &n);
	for (int i = 4; i <= n; i++) {
		N[i] = (N[i - 1] + N[i - 2]) % 10;
	}
	printf("%d", N[n]);
	return 0;
}