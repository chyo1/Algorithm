#include <stdio.h>
int main() {
	int N, M, boong[11][11];
	char s[11];
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", s);
		for (int j = 0; j < M; j++) {
			boong[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = M - 1; j >= 0; j--) {
			printf("%d", boong[i][j]);
		}
		printf("\n");
	}

	return 0;
}