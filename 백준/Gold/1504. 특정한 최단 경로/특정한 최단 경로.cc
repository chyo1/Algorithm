#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 100000000

vector <pair<int, int>> V[801];
int Distance[801];

int Dijkstra(int start, int end, int N) {
	if (start == end) return 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int now, dis, next;
	int D[801];

	fill(D, D + N, MAX);
	D[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		now = pq.top().second, dis = pq.top().first;
		pq.pop();
		if (D[now] < dis) continue;

		for (int i = 0; i < V[now].size(); i++) {
			next = V[now][i].first, dis = V[now][i].second;
			if (D[next] > D[now] + dis) {
				D[next] = D[now] + dis;
				pq.push({ D[next],next });
			}
		}
	}
	return D[end];
}
int main() {
	int N, E, v1, v2;
	int a, b, c, dis, dis1, dis2;
	scanf("%d %d", &N, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		V[a].push_back({ b,c });
		V[b].push_back({ a,c });
	}
	scanf("%d %d", &v1, &v2);

	a = Dijkstra(1, v1, N + 1);
	b = Dijkstra(v1, v2, N + 1);
	c = Dijkstra(v2, N, N + 1);
	if (a != MAX && b != MAX && c != MAX) dis1 = a + b + c;
	else dis1 = -1;

	a = Dijkstra(1, v2, N + 1);
	b = Dijkstra(v2, v1, N + 1);
	c = Dijkstra(v1, N, N + 1);
	if (a != MAX && b != MAX && c != MAX) dis2 = a + b + c;
	else dis2 = -1;

	if (dis1 != -1 && dis2 != -1) dis = dis1 < dis2 ? dis1 : dis2;
	else if (dis1 == -1 && dis2 == -1) dis = -1;
	else if (dis1 == -1) dis = dis2;
	else dis = dis1;
	printf("%d", dis);
	return 0;
}