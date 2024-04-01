#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

queue <int> Q;

int main() {
	int i, N, num;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) Q.push(i);
	while (Q.size() != 1) {
		Q.pop();
		if (Q.size() == 1) break;
		num = Q.front();
		Q.pop();
		Q.push(num);
	}
	printf("%d", Q.front());
	return 0;
}