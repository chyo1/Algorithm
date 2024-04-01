#include <stdio.h>
#include <queue>
using namespace std;
priority_queue <int, vector<int>, greater<int> > Q;
int main() {
	int N, num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		Q.push(num);
	}
	while (!Q.empty()) {
		printf("%d\n", Q.top());
		Q.pop();
	}
	return 0;
}