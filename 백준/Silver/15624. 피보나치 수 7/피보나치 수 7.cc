#include <stdio.h>
int Fn[1000001] = { 0,1,1 };
int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 3; i <= n; i++) Fn[i] = (Fn[i - 1] + Fn[i - 2])%1000000007;
	printf("%d", Fn[n]);
	return 0;
}