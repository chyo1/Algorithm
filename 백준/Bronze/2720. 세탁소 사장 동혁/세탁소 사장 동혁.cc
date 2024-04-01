#include <stdio.h>

int main() {
	int T, C;
	int change[4] = { 25,10,5,1 };

	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &C);

		for (int i = 0; i < 4; i++) {
			printf("%d ", C / change[i]);
			C %= change[i];
		}
		printf("\n");
	}
	return 0;
}