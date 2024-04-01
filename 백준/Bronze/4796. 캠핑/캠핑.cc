#include <stdio.h>

int main() {
	int L, P, V, cnt = 1, days;
	while (1) {
		scanf("%d %d %d", &L, &P, &V);
		if (!L && !P && !V) break;

		days = (V / P)*L;
		if (V%P > L) days += L;
		else days += V % P;

		printf("Case %d: %d\n", cnt++, days);
	}
	return 0;
}