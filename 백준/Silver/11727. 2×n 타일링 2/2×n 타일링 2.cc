#include <stdio.h>
int main() {
	int n, i;
	int D[1001] = { 0,1,3 };
	scanf("%d", &n);
	for (i = 3; i <= n; i++) D[i] = (D[i - 1] + 2 * D[i - 2]) % 10007;
	printf("%d", D[n]);
	return 0;
}