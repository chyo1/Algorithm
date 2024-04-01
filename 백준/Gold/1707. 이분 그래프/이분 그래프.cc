#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector <int> G[20001];
int visited[20001];


bool BFS(int start) {
	queue <int> Q;
	int now, color;

	if (!visited[start]) visited[start] = 1;
	Q.push(start);

	while (!Q.empty()) {
		now = Q.front();
		color = visited[now];
		Q.pop();
		for (int i : G[now]) {
			if (!visited[i]) {
				if (color == 1) visited[i] = -1;
				else if (color == -1) visited[i] = 1;
				Q.push(i);
			}
			else {
				if (color == visited[i]) return false;
			}
		}
	}
	return true;
}
bool BFS_level(int start) {
	queue <int> Q;
	int color = visited[start];
	for (int i : G[start]) {
		if (color == visited[i]) return false;
	}
	return true;
}

bool Is_Bip(int N) {
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			if (!BFS(i)) return false;
		}
		else BFS_level(i);
	}
	return true;
}
int main() {
	int K, V, E, a, b;
	scanf("%d", &K);
	for (int k = 0; k < K; k++) {
		scanf("%d %d", &V, &E);

		for (int i = 0; i < E; i++) {
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		if (Is_Bip(V)) printf("YES\n");
		else printf("NO\n");

		// init
		fill(visited, visited + V + 1, false);
		for (int i = 1; i <= V; i++) G[i].clear();

	}
	return 0;
}