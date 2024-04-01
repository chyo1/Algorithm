#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
int visited[100001];
int Find(int start, int end) {
	if (start == end) return 0;
	int now, sec, d[3] = { -1,1 }, min = 10000000;
	queue <pair<int, int>> Q;

	Q.push({ start, 0 });
	visited[start] = 0;
	fill(visited, visited + 100001, min);

	while (!Q.empty()) {
		now = Q.front().first, sec = Q.front().second;
		Q.pop();

		if (sec >= min) continue;
		d[2] = now;
		for (int i = 0; i < 3; i++) {
			int next = now + d[i];
			if (next < 0 || next > 100000 || visited[next] <= sec) continue;

			if (next == end) {
				if (i != 2) min = min < sec + 1 ? min : sec + 1;
				else min = min < sec ? min : sec;
				visited[next] = min;
			}
			else {
				if (i != 2) {
					if (sec + 1 < min) Q.push({ next, sec + 1 });
					visited[next] = sec + 1;
				}
				else {
					Q.push({ next, sec });
					visited[next] = sec;
				}
			}
		}
	}

	return min;
}
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d",Find(N, K));
	return 0;
}