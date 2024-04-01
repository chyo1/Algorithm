#include <stdio.h>
int main() {
	int max = -1, max_i, max_j;
	int A[10][10];
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			scanf("%d", &A[i][j]);
			if (A[i][j] > max) max = A[i][j], max_i = i, max_j = j;
		}
	}
	printf("%d\n%d %d", max, max_i, max_j);
	return 0;
}