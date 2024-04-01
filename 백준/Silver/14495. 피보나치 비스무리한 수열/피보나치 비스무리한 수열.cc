#include <stdio.h>
int main() {
	int n;
	long int F[117] = { 0, 1,1,1 };
	scanf("%d", &n);
	for (int i = 4; i <= n; i++)
		F[i] = F[i - 3] + F[i - 1];
	printf("%ld", F[n]);
	return 0;
}