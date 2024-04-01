#include <stdio.h>

bool Is_Tri(int a, int b, int c) {
	if ((a > b&&a > c)&& (a >= b + c)) return false;
	if ((b > a&&b > c) && (b >= a + c)) return false;
	if ((c > a&&c > b) && (c >= a + b)) return false;
	return true;
}

int main() {
	int a, b, c;
    
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (!a && !b && !c) break;

		if (!Is_Tri(a, b, c)) {
			printf("Invalid\n");
			continue;
		}

		if (a == b && a == c && b == c) printf("Equilateral\n");
		else {
			if (a != b && a != c && b != c) printf("Scalene\n");
			else printf("Isosceles\n");
		}
	}
	return 0;
}