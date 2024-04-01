#include <stdio.h>
int main() {
	int N, i, j, big;
	int info[50][3]; // height, weight, rank;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d %d", &info[i][0], &info[i][1]);
	for (i = 0; i < N; i++) {
		big = 0;
		for (j = 0; j < N; j++) {
			if (info[i][0] < info[j][0] && info[i][1] < info[j][1]) big++;
		}
		info[i][2] = big + 1;
	}
	for (i = 0; i < N; i++) printf("%d ", info[i][2]);
	return 0;
}