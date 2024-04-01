#include <stdio.h>
int main() {
	int a, cnt;
	for (int i = 0; i < 3; i++) {
		cnt = 0;
		for (int j = 0; j < 4; j++) {
			scanf("%d", &a);
			if (a == 0) cnt++;
		}
		if (cnt == 1) printf("A\n");
		else if (cnt == 2) printf("B\n");
		else if (cnt == 3) printf("C\n");
		else if (cnt == 4) printf("D\n");
		else printf("E\n");
	}
	return 0;
}