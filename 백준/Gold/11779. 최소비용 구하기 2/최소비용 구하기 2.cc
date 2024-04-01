#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

vector <pair<int, int>> V[1001];
vector <int> S;
int Price[1001][2]; // 최소 비용과, 버스가 온 도시 저장
bool visited[1001];

void Bus(int start, int end) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

	// 출발 도시까지의 비용은 0, 출발도시의 이전 도시는 출발도시와 동일
	Price[start][0] = 0, Price[start][1] = start;
	pq.push({ Price[start][0], start });
	
	// 각 도시까지 가는 최소 비용 구하기
	while (!pq.empty()) {
		int now = pq.top().second, now_price = pq.top().first;
		pq.pop();
		visited[now] = true;

		if (Price[now][0] < now_price) continue;

		for (int i = 0; i < V[now].size();i++) {
			int next = V[now][i].first, next_price = V[now][i].second;
		
			if (visited[next]) continue;

			if (Price[next][0] > now_price + next_price) {
				Price[next][0] = now_price + next_price;
				
				// 경로가 갱신될 때 어느 도시에서 왔는지 저장
				Price[next][1] = now;
				pq.push({ Price[next][0], next }); 
			}
		}
	}

	// 최소 비용을 갖는 경로 구하기
	int before = end;
	while (1) {
		if (before == Price[before][1]) break; // 출발도시일 때
		S.push_back(before);
		
		// 해당 도시 전에 왔던 도시로 이동
		before = Price[before][1];
	}
	S.push_back(start);

	// print
	printf("%d\n%d\n", Price[end][0], S.size());
	for (int i = S.size() - 1; i >= 0; i--) printf("%d ", S[i]);
}
int main() {
	int n, m;
	int start, end, cost;

	// input
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &start, &end, &cost);
		V[start].push_back({ end, cost });
	}
	scanf("%d %d", &start, &end);

	fill(Price[1], Price[n + 1], INT_MAX);
	Bus(start, end);

	return 0;
}