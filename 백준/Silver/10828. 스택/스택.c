#include <stdio.h>
#include <string.h>
int main() {
	int N, i, j = 0, num[10000];
	char CMD[6];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", CMD);
		if (!strcmp(CMD, "push")) scanf("%d", &num[j++]);

		else if (!strcmp(CMD, "top")) {
			if (j <= 0) printf("-1\n");
			else printf("%d\n", num[j - 1]);
		}

		else if (!strcmp(CMD, "pop")) {
			if (j <= 0) printf("-1\n");
			else printf("%d\n", num[--j]);
		}

		else if (!strcmp(CMD, "size"))	printf("%d\n", j);

		else if (!strcmp(CMD, "empty")) {
			if (j == 0) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}