#include <stdio.h>
#include <queue>
using namespace std;

queue <int> Q;

int main() {
	int N, n;
	scanf("%d", &N);
	while (1) {
		scanf("%d", &n);
		if (n == 0) Q.pop();
		else if (n == -1) break;
		else {
			if (Q.size() < N) Q.push(n);
		}
	}
	if (Q.empty()) printf("empty");

	while (!Q.empty()) {
		printf("%d ", Q.front());
		Q.pop();
	}
}