#include <stdio.h>
int main() {
	int T, R, i, j = 0, k;
	char S[21];
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d%s", &R, &S);
		while (S[j] != NULL) {
			for (k = 0; k < R; k++) printf("%c", S[j]);
			j++;
		}
		j = 0;
		printf("\n");
	}
}