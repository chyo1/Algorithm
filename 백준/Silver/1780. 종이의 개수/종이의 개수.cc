#include <stdio.h>
int A[2200][2200];
int n0 = 0, n1 = 0, n_1 = 0;
void D(int a, int b, int N) {
	int i, j, num;

	num = A[a][b];
	for (i = a; i < a + N; i++) {
		for (j = b; j < b + N; j++) {
			if (A[i][j] != num) break;
		}
		if (j != b + N) break;
	}
	if (i == a + N && j == b + N) {
		if (!num) n0++;
		else if (num == 1) n1++;
		else n_1++;
	}
	else {
		for (i = a; i < a + N; i = i + N / 3) {
			for (j = b; j < b + N; j = j + N / 3) {
				D(i, j, N / 3);
			}
		}
	}
}
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			scanf("%d", &A[i][j]);
	}

	D(0, 0, N);
	printf("%d\n%d\n%d", n_1, n0, n1);
	return 0;
}