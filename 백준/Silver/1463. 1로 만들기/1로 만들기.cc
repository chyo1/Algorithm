#include <stdio.h>
int DP[1000001] = { 0,0,1,1,2, };
int MIN(int a, int b) { return a < b ? a : b; }
int main() {
	int X;
	scanf("%d", &X);

	for (int i = 5; i <= X; i++) {
		DP[i] = DP[i - 1] + 1;
		if (i % 3 == 0) DP[i] = MIN(DP[i], DP[i / 3] + 1);
		if(i%2==0) DP[i] = MIN(DP[i], DP[i / 2] + 1);
	}
	printf("%d", DP[X]);
	return 0;
}