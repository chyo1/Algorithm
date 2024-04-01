#include <stdio.h>

int main() {
	int map[101][101] = { 0, };
	int x1, x2, y1, y2, cnt = 0;
	int line[10] = { 0, };

	for (int i = 0; i < 4; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
		for (int m = x1; m < x2; m++) {
			for (int n = y1; n < y2; n++) {
                
				if (!map[m][n]) {
					cnt++;
					map[m][n] = 1;
				}
			}
		}
	}

	printf("%d", cnt);
	return 0;
}