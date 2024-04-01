#include <stdio.h>
int N, M, A[50][50];

int get_S() {
	int size, vertex;
	size = N > M ? M - 1 : N - 1;
	while (1) {
		for (int i = 0; i < N - size; i++) {
			for (int j = 0; j < M - size; j++) {
				vertex = A[i][j];
				if (A[i + size][j] == vertex && A[i][j + size] == vertex && A[i + size][j + size] == vertex)
					return (size + 1) * (size + 1);
			}
		}
		size--;
		if (!size) return 1;
	}
}
int main() {
	char s[50];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", s);
		for (int j = 0; j < M; j++) {
			A[i][j] = s[j] - '0';
		}
	}
	printf("%d", get_S());
	return 0;
}