#include <stdio.h>
#include <math.h>

int Is_in(int x, int y, int rx, int ry, int r) {
	int d = (x - rx)*(x - rx) + (y - ry)*(y - ry);
	if (d > r*r) return 0;
	else return 1;
}
int main() {
	int T, N;
	int x1, x2, y1, y2, Cx, Cy, r;
	int cnt = 0, cnt_s, cnt_e;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2); // 출발점 : (x1,y1) 도착점 : (x2,y2)

		scanf("%d", &N); // 행성계의 개수
		for (int n = 0; n < N; n++) {
			scanf("%d %d %d", &Cx, &Cy, &r); // 행성계의 중점 : (Cx,Cy), 반지름 : r
			cnt_s = Is_in(x1, y1, Cx, Cy, r);
			cnt_e = Is_in(x2, y2, Cx, Cy, r);
			if (cnt_s + cnt_e == 2) continue;
			cnt += (cnt_s + cnt_e);
		}
		printf("%d\n", cnt);
		cnt = 0;
	}
	return 0;
}