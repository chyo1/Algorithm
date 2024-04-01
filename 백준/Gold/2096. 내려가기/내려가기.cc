#include <stdio.h>
#include <algorithm>
using namespace std;

int DP[100000][3][2];

int Get(int a, int b, int c, bool min) {
	int m, M;
	if (a > b) {
		if (b > c) m = c, M = a; // a>b>c

		else { // c>=b
			if (c > a) m = b, M = c; // c>a>=b
			else m = b, M = a; // a>=c>=b
		}
	}
	else { // b>=a
		if (a > c) m = c, M = b; // b>=a>c

		else { //c>=a
			if (c > b) m = a, M = c; // c>b>=a
			else m = a, M = b; // b>=c>=a
		}
	}
	if (min) return m;
	else return M;
}

int main() {
	int N, min, Max;
	int a, b, c;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &a, &b, &c);
		DP[i][0][0] = DP[i][0][1] = a;
		DP[i][1][0] = DP[i][1][1] = b;
		DP[i][2][0] = DP[i][2][1] = c;
	}

	for (int i = 1; i < N; i++) {
		int m1 = DP[i - 1][0][0], m2 = DP[i - 1][1][0], m3 = DP[i - 1][2][0],
			M1 = DP[i - 1][0][1], M2 = DP[i - 1][1][1], M3 = DP[i - 1][2][1];

		DP[i][0][0] += m1 < m2 ? m1 : m2, DP[i][2][0] += m2 < m3 ? m2 : m3;
		DP[i][0][1] += M1 > M2 ? M1 : M2, DP[i][2][1] += M2 > M3 ? M2 : M3;

		min = Get(m1,m2,m3, true), Max = Get(M1,M2,M3, false);
		DP[i][1][0] += min;
		DP[i][1][1] += Max;
	}
	printf("%d ", Get(DP[N - 1][0][1], DP[N - 1][1][1], DP[N - 1][2][1], false));
	printf("%d", Get(DP[N-1][0][0], DP[N-1][1][0], DP[N-1][2][0], true));	
	return 0;
}