#include <stdio.h>
int main() {
	int N = 0, K, M, dol[50];
	int i, j;
	double a = 0, sum = 1, total = 1;

	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d", &dol[i]);
		N += dol[i];
	}
	scanf("%d", &K);

	for (i = 0; i < M; i++) {
		for (j = 0; j < K; j++)
			sum *= dol[i]--;
		a += sum, sum = 1;
	}
	// 모두 같은 공이 나오는 경우의 수

	for (i = 0; i < K; i++) total *= N--; // 전체 경우의 수
	printf("%.15lf", a / total);
	return 0;
}