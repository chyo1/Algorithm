#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int t, a, b;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}

	return 0;
}