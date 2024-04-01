#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define LIMITS 100000000
vector <pair<int, int>> V[50001];

int Cow[50001]; // 최소 시간, 직전 집하장 저장
int table[201][201]; // 경로표
bool visited[1001];

int Way(int start, int n) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

	// start
	Cow[start] = 0;
	pq.push({ Cow[start], start });

	// 최소 비용 구하기 -> Dijkstra
	while (!pq.empty()) {
		int now = pq.top().second, now_cow = pq.top().first;
		pq.pop();
		visited[now] = true;

		// 현재 저장된 값이 큐에 저장됐던 값보다 작을 경우 실행 x
		if (Cow[now] < now_cow) continue;

		for (int i = 0; i < V[now].size(); i++) {
			int next = V[now][i].first, next_cow = V[now][i].second;

			if (visited[next]) continue;

			if (Cow[next] > now_cow + next_cow) {

				// 최소 비용 갱신 및 큐에 저장
				Cow[next] = now_cow + next_cow;
				pq.push({ Cow[next], next });
			}
		}
	}
	return Cow[n];
}
int main() {
	int n, m;
	int start, end, cost;

	// input
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &start, &end, &cost);
		V[start].push_back({ end, cost });
		V[end].push_back({ start, cost });
	}

	// Search
	fill(Cow, Cow + n + 1, LIMITS);
	printf("%d", Way(1, n));

	return 0;
}