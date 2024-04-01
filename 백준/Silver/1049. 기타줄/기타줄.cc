#include <stdio.h>
int prize[50][2];

int Get_Min(int n, int min6, int min) {
	int price = 0;
	if (min6 > min * 6) return min * n;
	price += (n / 6)*min6;
	n %= 6;
	if (min6 < min*n) price += min6;
	else price += n * min;
	return price;
}

int main() {
	int N, M;
	int m = 1001, m6 = 1001;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &prize[i][0], &prize[i][1]);
		if (m6 > prize[i][0]) m6 = prize[i][0];
		if (m > prize[i][1]) m = prize[i][1];
	}
	printf("%d", Get_Min(N, m6, m));

	return 0;
}