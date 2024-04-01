#include <stdio.h>
#include <math.h>
int Can(int, int, int);
int main() {
	int T;
	int x1, x2, y1, y2, r1, r2;
	double dis;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		dis = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
		printf("%d\n", Can((r1 - r2)*(r1 - r2), (r1 + r2)*(r1 + r2), dis));
	}
	return 0;
}
int Can(int dis_m, int dis_p, int d) {
	if (!d && !dis_m) return -1; // 두 원이 같을 때
	if (dis_m < d && d < dis_p) return 2;
	else if (dis_m == d || dis_p == d) return 1;
	else if (d < dis_m || dis_p < d) return 0;
	//return -1;
}