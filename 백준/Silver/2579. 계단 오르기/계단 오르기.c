#include<stdio.h>
int max(int a, int b);
int main() {
	int n, sum[301], score[301];
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &score[i]);
	sum[0] = 0;
	sum[1] = score[1];
	sum[2] = score[1] + score[2];

	for (i = 3; i <= n; i++)
		sum[i] = max(sum[i - 3] + score[i - 1] + score[i], sum[i - 2] + score[i]);
	printf("%d", sum[n]);
}
int max(int a, int b) {
	return a > b ? a : b;
}