#include <stdio.h>
#include <math.h>
int main() {
	long long int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	if (B >= C) printf("-1"); // 손익분기점 존재 X
	else printf("%d", A / (C - B) + 1);
	return 0;
}