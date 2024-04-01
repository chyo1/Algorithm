#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int item[101], dis[101];
bool visited[101];
vector <pair<int, int>> V[101];

int Search(int start, int len, int N) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

	// 출발지점 지정
	dis[start] = 0;
	Q.push({ dis[start], start });
	visited[start] = true;

	// 출발지점에서 모든 노드까지의 최소 거리 구하기, Dijkstra
	while (!Q.empty()) {
		int now = Q.top().second, dis_now = Q.top().first;
		Q.pop();
		visited[now] = true;

		for (int i = 0; i < V[now].size(); i++) {
			int next = V[now][i].second, dis_next = V[now][i].first;

			if (visited[next]) continue;

			if (dis[next] > dis_now + dis_next) {
				dis[next] = dis_now + dis_next;
				Q.push({ dis[next], next });
			}
		}
	}

	// 수색 범위 내에 있는 아이템의 총 개수 구하기
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (dis[i] <= len) sum += item[i];
	}

	return sum;
}
int main() {
	int n, m, r;
	int a, b, l;
	int max = 0;

	// input
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= n; i++) scanf("%d", &item[i]);

	for (int i = 0; i < r; i++) {
		scanf("%d %d %d", &a, &b, &l);

		// 양방향 그래프
		V[a].push_back({ l,b });
		V[b].push_back({ l,a });
	}

	// 모든 출발지에서 얻을 수 있는 아이템 개수 구하기
	for (int i = 1; i <= n; i++) {

		// init
		fill(dis, dis + n + 1, 1000000);
		fill(visited, visited + n + 1, false);

		int sum = Search(i, m, n);
		if (max < sum) max = sum;
	}

	printf("%d", max);
	return 0;
}