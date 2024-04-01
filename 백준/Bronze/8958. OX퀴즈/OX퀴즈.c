#include <stdio.h>
int main() {
	int N, i, j, cnt, sum;
	char arr[81];
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%s", arr);
		cnt = sum = 0;

		j = 0;
		while (arr[j] != NULL) {
			if (arr[j] == 'O') cnt++, sum+=cnt;
			else cnt = 0;
			j++;
		}

		printf("%d\n", sum);
	}
}