#include <stdio.h>
int main() {
	int N, L, mid, s, e, sum_m, sum_M;
	bool change = true;
	scanf("%d %d", &N, &L);
	while (1) {
		if (change) {
			mid = N / L;
			if (L % 2) s = mid - L / 2, e = mid + L / 2;
			else s = mid - L / 2 + 1, e = mid + L / 2;

			if (L % 2) sum_m = mid + (2 * mid)*(L / 2);
			else sum_m = (2 * mid + 1)*(L / 2);

			sum_M = sum_m - s + (e + 1);

			change = false;
		}

		//error
		if (s < 0 || e - s + 1>100) {
			printf("-1");
			return 0;
		}

		if (sum_m == N) break;
		else if (sum_M == N) {
			s++, e++;
			break;
		}

		if (sum_m < N&&N < sum_M) L++, change = true;
		else if (N < sum_m) sum_M = sum_m, sum_m = sum_m - e + (s - 1);
		else if (N > sum_M) sum_m = sum_M, sum_M = sum_M + (e + 2) - (s + 1);
	}
	//print
	for (int i = s; i <= e; i++) printf("%d ", i);

	return 0;
}