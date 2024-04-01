#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;


int map[126][126], w[126][126];
bool visited[126][126];
int Search(int N) {
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > Q;
		
	w[0][0] = map[0][0];
	visited[0][0] = true;
	Q.push({ w[0][0],{0,0} });

	int x, y, nx, ny, weight;
	int m[4][2] = { {-1,0}, {1,0},{0,1},{0,-1} };
	while (!Q.empty()) {
		x = Q.top().second.first, y = Q.top().second.second, weight = Q.top().first;
		Q.pop();

		if (x == N - 1 && y == N - 1) return weight;

		for (int i = 0; i < 4; i++) {
			nx = x + m[i][0], ny = y + m[i][1];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]) continue;
			visited[nx][ny] = true;
			if (w[nx][ny] > weight + map[nx][ny]) {
				w[nx][ny] = weight + map[nx][ny];
				Q.push({ w[nx][ny],{nx,ny} });
			}
		}
	}
}


int main() {
	int N, cnt = 1;

	fill(w[0], w[126], 500000);

	while (1) {
		// input
		scanf("%d", &N);
		if (N == 0) break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) scanf("%d", &map[i][j]);
		}

		printf("Problem %d: %d\n", cnt, Search(N));

		// init
		fill(map[0], map[N], 0);
		fill(w[0], w[N], 500000);
		fill(visited[0], visited[N], false);
		cnt++;
	}
	return 0;
}