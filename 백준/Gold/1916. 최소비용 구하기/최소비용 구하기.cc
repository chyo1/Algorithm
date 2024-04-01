#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<pair<int, int>> C[1001];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int W[20001];

void Dijkstra(int s) {
	int now, next, weight;
	pq.push({ 0,s });
	W[s] = 0;
	while (!pq.empty()) {
		now = pq.top().second, weight = pq.top().first;
		pq.pop();
		if (W[now] < weight) continue;
		for (int i = 0; i < C[now].size(); i++) {
			next = C[now][i].first, weight = C[now][i].second;
			if (W[next] > W[now] + weight) {
				W[next] = W[now] + weight;
				pq.push({ W[next],next });
			}
		}
	}
}

int main() {
	int N, M;
	int s, e, w;
	int start, end;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &e, &w);
		C[s].push_back({ e,w });
	}
	scanf("%d %d", &start, &end);

	fill(W, W + N + 1, INT_MAX);
	Dijkstra(start);

	printf("%d", W[end]);
	return 0;
}