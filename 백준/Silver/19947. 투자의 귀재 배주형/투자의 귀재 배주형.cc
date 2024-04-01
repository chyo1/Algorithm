#include <stdio.h>
int max(int a, int b) { return a > b ? a : b; }
int main() {
	int H, Y, sum[10];
	scanf("%d %d", &H, &Y);
	sum[0] = H;
	sum[1] = H * 1.05;
	sum[2] = sum[1] * 1.05;
	sum[3] = max(H*1.2, sum[2] * 1.05);
	sum[4] = max(sum[3] * 1.05, sum[1] * 1.2);

	for (int i = 5; i <= 10; i++) {
		sum[i] = max((max(sum[i - 3] * 1.2, sum[i - 1] * 1.05)), sum[i - 5] * 1.35);
	}
	printf("%d", sum[Y]);
	return 0;
}