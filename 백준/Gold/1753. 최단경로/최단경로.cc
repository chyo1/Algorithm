#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<pair<int, int>> R[20001];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
int W[20001];

void Dijkstra(int s) {
	int now, next, weight;
	Q.push({ 0,s });
	W[s] = 0;
	while (!Q.empty()) {
		now = Q.top().second, weight = Q.top().first;
		Q.pop();

		//if (W[now] < weight) continue;

		for (int i = 0; i < R[now].size(); i++) {
			next = R[now][i].first, weight = R[now][i].second;
			if (W[next] > W[now] + weight) {
				W[next] = W[now] + weight;
				Q.push({ W[next], next });
			}
		}
	}
}

int main() {
	int V, E, start;
	int u, v, w;

	scanf("%d %d", &V, &E);
	scanf("%d", &start);

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		R[u].push_back({ v,w });
	}

	fill(W, W + V + 1, INT_MAX);
	Dijkstra(start);

	//print
	for (int i = 1; i <= V; i++) {
		if (W[i] == INT_MAX) printf("INF\n");
		else printf("%d\n", W[i]);
	}

	return 0;
}