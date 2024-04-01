#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

bool dash[540000];
void Blank(int n, int start) {
	if (n > 1) {
		n /= 3;
		Blank(n, start);
		for (int i = start+n; i < start + 2*n; i++) dash[i] = true;
		Blank(n, start + 2 * n);
	}
}

int main() {
	int N;

	while (scanf("%d", &N) != EOF) {
		fill(dash, dash + 540000, false);
		Blank(pow(3, N), 0);

		for (int i = 0; i < pow(3, N); i++) {
			if (dash[i]) printf(" ");
			else printf("-");
		}
		printf("\n");
	}
	return 0;
}