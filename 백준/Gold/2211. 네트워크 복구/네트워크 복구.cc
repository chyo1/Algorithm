#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

#define LIMITS 100000000
vector <pair<int, int>> V[50001];

int line[1001][2];
bool visited[1001];

void Recover(int start, int n) {
	printf("%d\n", n - 1);
	for (int i = 2; i <= n; i++) printf("%d %d\n", line[i][1], i);
}

void Com(int start, int n) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

	line[start][0] = line[start][1]= 0;
	pq.push({ line[start][0], start });

	while (!pq.empty()) {
		int now = pq.top().second, now_s = pq.top().first;
		pq.pop();
		visited[now] = true;

		if (line[now][0] < now_s) continue;

		for (int i = 0; i < V[now].size(); i++) {
			int next = V[now][i].first, next_s = V[now][i].second;

			if (visited[next]) continue;

			if (line[next][0] > now_s + next_s) {

				line[next][0] = now_s + next_s;
				line[next][1] = now;
				pq.push({ line[next][0], next });
			}
		}
	}
}
int main() {
	int n, m;
	int a, b, c;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		V[a].push_back({ b, c });
		V[b].push_back({ a, c });
	}

	fill(line[0], line[n + 1], LIMITS);
	Com(1, n);
	Recover(1, n);
	return 0;
}