#include <stdio.h>
#include <queue>
using namespace std;

queue <int> Q;

void P(int N, int K) {
	int cnt = 0, tmp;
	printf("<");
	while (1) {
		for (int i = 1; i < K; i++) {
			tmp = Q.front();
			Q.pop();
			Q.push(tmp);
		}
		printf("%d", Q.front());
		Q.pop();
		if (!Q.empty()) printf(", ");
		else break;
	}
	printf(">");
}

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) Q.push(i + 1);
	P(N, K);
	return 0;
}