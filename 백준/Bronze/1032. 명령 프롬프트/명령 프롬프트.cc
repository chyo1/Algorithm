#include <stdio.h>
#include <string.h>
int main() {
	int N, len;
	char A[51], cmp[51];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			scanf("%s", A);
			len = strlen(A);
		}
		else {
			scanf("%s", cmp);
			for (int j = 0; j < len; j++) {
				if (A[j] != cmp[j]) A[j] = '?';
			}
		}
	}
	printf("%s", A);
	return 0;
}