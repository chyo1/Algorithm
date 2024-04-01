#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

queue <int> Q;

int main() {
	int i, n, N;
	char s[6];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", &s);
		if (!strcmp(s, "push")) {
			scanf("%d", &n);
			Q.push(n);
		}
		else if (!strcmp(s, "pop")) {
			if (!Q.empty()) {
				printf("%d\n", Q.front());
				Q.pop();
			}
			else printf("-1\n");

		}
		else if (!strcmp(s, "size"))	printf("%d\n", Q.size());
		else if (!strcmp(s, "empty")) printf("%d\n", Q.empty());
		else if (!strcmp(s, "front")) {
			if(!Q.empty()) printf("%d\n",Q.front());
			else printf("-1\n");
		}
		else if (!strcmp(s, "back")) {
			if (!Q.empty()) {
				n = Q.back();
				printf("%d\n", n);
			}
			else printf("-1\n");
		}
	}

	return 0;
}