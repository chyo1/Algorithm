#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector <int> V[501];

int BFS(int sang) {
	int invite = 0, now, cnt;
	bool visited[501] = { 0, };
	queue <pair<int, int>> Q;

	Q.push({ 1, 0 });
	visited[sang] = true;
	while (!Q.empty()) {
		now = Q.front().first, cnt = Q.front().second;
		Q.pop();

		if (cnt >= 2) continue;

		for (int i : V[now]) {
			if (!visited[i]) {
				visited[i] = true;
				invite++;
				Q.push({ i,cnt + 1 });
			}
		}
	}
	return invite;
}

int main() {
	int n, m, a, b;

	// input
	scanf("%d\n%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		V[a].push_back(b);
		V[b].push_back(a);
	}

	printf("%d", BFS(1));
	return 0;
}