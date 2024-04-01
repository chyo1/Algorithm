#include <stdio.h>
int main() {
	int n, i, j;
	int tri[500][500];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			scanf("%d", &tri[i][j]);
		}
	}
	int sum = tri[0][0];
	for (i = 1; i < n; i++) {
		for (j = 0; j <= i; j++) {
			if (i == 1) tri[i][j] += tri[0][0];
			else if (i > 1) {
				if (j == 0) tri[i][j] += tri[i - 1][j];
				else if (j == i) tri[i][j] += tri[i - 1][j - 1];
				else {
					if (tri[i - 1][j - 1] > tri[i - 1][j]) tri[i][j] += tri[i - 1][j - 1];
					else tri[i][j] += tri[i - 1][j];
				}
			}
		}
	}
	int max = tri[n - 1][0];
	for (i = 1; i < n; i++) {
		if (tri[n - 1][i] > max) max = tri[n - 1][i];
	}
	printf("%d", max);
	return 0;
}