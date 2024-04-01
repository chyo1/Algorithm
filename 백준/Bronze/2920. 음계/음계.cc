#include <stdio.h>
int main() {
	int A[8], i;
	for (i = 0; i < 8; i++) scanf("%d", &A[i]);
	if (A[0] == 1) {
		for (i = 0; i < 7; i++) {
			if (A[i] >= A[i + 1]) break;
		}
		if (i != 7) printf("mixed\n");
		else printf("ascending\n");
	}
	else if (A[0] == 8) {
		for (i = 0; i < 7; i++) {
			if (A[i] <= A[i + 1]) break;
		}
		if (i != 7) printf("mixed\n");
		else printf("descending\n");
	}
	else printf("mixed\n");
	return 0;
}