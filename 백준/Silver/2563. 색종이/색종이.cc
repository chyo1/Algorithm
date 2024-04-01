#include <stdio.h>
bool A[100][100];
int main() {

	int x, y, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				A[i][j] = true;
			}
		}
	}
	int S = 0;
	for (int i =0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (A[i][j]) S++;
		}
	}
	printf("%d", S);
	return 0;
}