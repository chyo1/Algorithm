#include <stdio.h>
#include <queue>
using namespace std;

int main() {
	int N;
	queue <int> Q;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) Q.push(i);
	while (Q.size() > 1) {
		printf("%d ", Q.front());
		Q.pop();

		int top = Q.front();
		Q.pop(); Q.push(top);
	}
	printf("%d ", Q.front());
	return 0;
}