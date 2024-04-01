#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define LIMITS 1000000
vector <pair<int, int>> V[1001];

int Time[1001][2]; // 최소 시간, 직전 집하장 저장
int table[201][201]; // 경로표
bool visited[1001];

void Print(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) printf("- ");
			else printf("%d ", table[i][j]);
		}
		printf("\n");
	}
}
void Post(int start, int n) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

	// start
	Time[start][0] = 0, Time[start][1] = -1; // 0..?
	pq.push({Time[start][0], start});

	// 최소 시간 경로 구하기 -> Dijkstra
	while (!pq.empty()) {
		int now = pq.top().second, now_t = pq.top().first;
		pq.pop();
		visited[now] = true;

		// 현재 저장된 값이 큐에 저장됐던 값보다 작을 경우 실행 x
		if (Time[now][0] < now_t) continue;

		for (int i = 0; i < V[now].size(); i++) {
			int next = V[now][i].first, next_t = V[now][i].second;

			if (visited[next]) continue;

			if (Time[next][0] > now_t + next_t) {
				
				// 최소 시간 갱신 및 직전 집하장 저장
				Time[next][0] = now_t + next_t;
				Time[next][1] = now;

				// 갱신된 값은 큐에 저장
				pq.push({ Time[next][0], next });
			}
		}
	}

	// 출발 후 처음으로 거치는 경로 구하기
	for (int i = 1; i <= n; i++) {
		if (i == start) continue;
		int before = i;
		while (Time[before][1]!=start) before = Time[before][1];
		table[start][i] = before;
	}
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
	for (int i = 1; i <= n; i++) {
		fill(Time[1], Time[n + 1], LIMITS);
		fill(visited, visited + n + 1, false);
		Post(i, n);
	}

	Print(n);
	return 0;
}