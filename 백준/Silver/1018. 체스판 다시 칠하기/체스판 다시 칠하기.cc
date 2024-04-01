#include <stdio.h>
bool C[50][50];
int Get_cnt(bool f, int x, int y) {
	int cnt = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (C[i][j] != f) cnt++;

			f = not f; // f = ~f;
		}
		f = not f;
	}
	return cnt;
}
auto Paint(int x, int y) {
	int cnt1, cnt2;
	cnt1=Get_cnt(true, x, y);
	cnt2 = Get_cnt(false, x, y);

	if (cnt1 > cnt2) return cnt2;
	else return cnt1;
}
auto Rev(int N, int M) {
	int min = 3000, cnt;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			cnt = Paint(i, j);
			if (cnt < min) min = cnt;
		}
	}
	return min;
}
int main() {
	int N, M;
	int i, j;

	char c;
	scanf("%d %d", &N, &M);
	
	for (i = 0; i < N; i++) {
		scanf("%c", &c); // \n
		for (j = 0; j < M; j++) {
			scanf("%c", &c);
			if (c == 'B') C[i][j] = false;
			else if (c == 'W') C[i][j] = true;
			else C[i][j] = true;
		}
	}
	printf("%d", Rev(N, M));
	return 0;
}