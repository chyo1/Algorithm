#include <stdio.h>
int main() {
	int a, b;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) break;
		if (b / a != 0) { // b > a
			if (b%a == 0) printf("factor\n");// a가 b의 약수
			else printf("neither\n"); 
		}
		else { //a>b
			if (a%b == 0) printf("multiple\n");
			else printf("neither\n");
		}
	}
	return 0;
}