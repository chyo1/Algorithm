#include <stdio.h>
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (a + b + c >= 100) printf("OK");
	else {

		if (a < b) {
			// a < b < c
			if (b < c) printf("Soongsil");

			// a < c <= b
			else if (a < c) printf("Soongsil");

			// c <= a < b
			else printf("Hanyang");
		}

		// b <= a
		else {
			// c < b <= a
			if (c < b) printf("Hanyang");

			// b <= c < a
			else if (c < a) printf("Korea");

			// b <= a <= c
			else printf("Korea");
		}
	}

	return 0;
}