#include <stdio.h>
#include <iostream>
#include <string.h>
#include<algorithm>
using namespace std;

int main() {
	int M, n;
	bool num[21] = { 0, };
	char s[10];

	scanf("%d\n", &M);
	for (int i = 0; i < M; i++) {
		scanf("%s", s);

		if (!strcmp(s, "add")) {
			scanf("%d", &n);
			num[n] = true;
		}
		else if (!strcmp(s, "remove")) {
			scanf("%d", &n);
			num[n] = false;
		}

		else if (!strcmp(s, "check")) {
			scanf("%d", &n);
			printf("%d\n", num[n]);
		}

		else if (!strcmp(s, "toggle")) {
			scanf("%d", &n);
			num[n] = !num[n];
		}

		else if (!strcmp(s, "all")) fill(num, num + 21, true);

		else if (!strcmp(s, "empty")) fill(num, num + 21, false);
	}
	return 0;
}