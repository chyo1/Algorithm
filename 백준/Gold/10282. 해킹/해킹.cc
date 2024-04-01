#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

vector <pair<int, int>> Com[10001];
int Sec[10001];

pair<int, int> infection(int start, int N) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	bool visited[10001] = { false, };

	// 출발 지점 값 정하기
	fill(Sec, Sec + N + 1, INT_MAX); // max 값으로 초기화
	Sec[start] = 0;
	pq.push({ Sec[start],start });
	visited[start] = true;

	// 연결된 컴퓨터가 해킹되는 시간 구하기 -> Dijkstra
	while (!pq.empty()) {
		int now = pq.top().second, now_sec = pq.top().first;
		pq.pop();

		for (int i = 0; i < Com[now].size(); i++) {
			int next = Com[now][i].first, next_sec = Com[now][i].second;

			if (visited[next]) continue;
			if (Sec[next] > now_sec + next_sec) {
				Sec[next] = now_sec + next_sec;
				pq.push({ Sec[next], next });
			}
		}
	}
	
	// 감염된 컴퓨터의 개수와 그 중 가장 오래 걸리는 시간 찾기
	int max = 0, cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (Sec[i] != INT_MAX) {
			cnt++;
			if (max < Sec[i]) max = Sec[i];
		}
	}
	return { cnt, max };
}
int main() {
	int T;
	int n, d, c;
	int a, b, s;

	// input
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d %d", &n, &d, &c);
		for (int i = 0; i < d; i++) {
			scanf("%d %d %d", &a, &b, &s);
			Com[b].push_back({ a,s });
		}

		// print
		pair<int, int> Ans = infection(c, n);
		printf("%d %d\n", Ans.first, Ans.second);

		// init
		for (int i = 1; i <= n; i++) Com[i].clear();
	}

	return 0;
}