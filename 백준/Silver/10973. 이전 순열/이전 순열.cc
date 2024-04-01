#include <stdio.h>

int num[10001], flag[10001];
int main() {
	int n, i;

	// input
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &num[i]);

	int loc = n - 1;
	while (num[loc] < num[loc + 1] && loc > 0) loc--;

	// 사전순으로 가장 처음에 오는 순열
	if (!loc) printf("-1");

	else {
		for (int i = 1; i < loc; i++) {
			printf("%d ", num[i]);
			flag[num[i]]++;
		}

		for (i = num[loc]-1; i > 0; i--) {
			if (!flag[i]) {
				printf("%d ", i);
				flag[i] = true;
				break;
			}
		}
		for (i = n; i > 0; i--) {
			if (!flag[i]) printf("%d ", i);
		}
	}

	return 0;
}