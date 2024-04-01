#include <stdio.h>
int main() {
	char A[1001], B[1001];
	int i = 0, j = 0;
	
	scanf("%s\n%s", A, B);
	
	while (A[i++] != NULL);
	while (B[j++] != NULL);
	
	if (i >= j) printf("go\n");
	else printf("no\n");

	return 0;
}