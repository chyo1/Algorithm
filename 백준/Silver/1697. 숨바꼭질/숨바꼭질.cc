#include <stdio.h>
#include <queue>
using namespace std;

int Find(int start, int end) {
	if (start == end) return 0;

	int now, next;
	int move[3] = { 1,-1 };
	queue <int> Q;
	int visited[100001] = { 0, };

	Q.push(start); visited[start] = true;

	while (!Q.empty()) {
		now = Q.front(); Q.pop();
		move[2] = now;

		for (int i = 0; i < 3; i++) {
			next = now + move[i];
			if (next < 0 || 100000 < next) continue;
			if (!visited[next]) {

				if (next == end) return visited[now];

				Q.push(next);
				visited[next] = visited[now] + 1;
			}
		}
	}
}

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d", Find(N, K));
	return 0;
}