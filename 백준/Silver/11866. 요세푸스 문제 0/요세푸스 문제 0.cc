#include <stdio.h>
#include <queue>
using namespace std;

queue <int> Q;

int main() {
	int N, K, cnt = 0;
	int i, num;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) Q.push(i);

	printf("<");
	cnt = 0, num = 0;
	while (!Q.empty()) {
		for (i = 1; i < K; i++) {
			num = Q.front();
			Q.pop();
			Q.push(num);
		}
		printf("%d", Q.front());
		Q.pop();
		num++;

		if (!Q.empty()) printf(", ");
	}
	printf(">");
	return 0;
}