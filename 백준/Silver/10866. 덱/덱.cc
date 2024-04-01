#include <stdio.h>
#include <deque>
#include <string.h>
using namespace std;

deque <int> Q;

int main() {
	int i, n, N;
	char s[11];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", &s);
		if (!strcmp(s, "push_front")) {
			scanf("%d", &n);
			Q.push_front(n);
		}
		else if (!strcmp(s, "push_back")) {
			scanf("%d", &n);
			Q.push_back(n);
		}

		else if (!strcmp(s, "pop_front")) {
			if (!Q.empty()) {
				printf("%d\n", Q.front());
				Q.pop_front();
			}
			else printf("-1\n");
		}
		else if (!strcmp(s, "pop_back")) {
			if (!Q.empty()) {
				printf("%d\n", Q.back());
				Q.pop_back();
			}
			else printf("-1\n");
		}

		else if (!strcmp(s, "size")) printf("%d\n", Q.size());
		else if (!strcmp(s, "empty")) printf("%d\n", Q.empty());
		else if (!strcmp(s, "front")) {
			if (!Q.empty()) printf("%d\n", Q.front());
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