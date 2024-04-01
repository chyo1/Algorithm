#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool map[51][51], visited[51][51];
vector <pair<int, int>> V;

int Time(int R, int C) {
	int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
	int max = 0, x, y, nx, ny, cnt;
	queue <pair<pair<int, int>, int>> Q;

	for (int i = 0; i < V.size(); i++) {
		// init
		fill(visited[0], visited[R], 0);
		cnt = 0;
		Q.push({ { V[i].first, V[i].second },0 });
		visited[V[i].first][V[i].second] = true;

		while (!Q.empty()) {
			x = Q.front().first.first, y = Q.front().first.second, cnt = Q.front().second;
			Q.pop();

			for (int j = 0; j < 4; j++) {
				nx = x + d[j][0], ny = y + d[j][1];
				if (visited[nx][ny] || !map[nx][ny] || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

				visited[nx][ny] = true;
				Q.push({ {nx,ny}, cnt + 1 });

				max = max > cnt + 1 ? max : cnt + 1;
			}
		}
	}
	return max;
}

int main() {
	int R, C;
	char s[50];

	// input
	scanf("%d %d\n", &R, &C);
	for (int i = 0; i < R; i++) {
		scanf("%s", s);
		for (int j = 0; j < C; j++) {
			if (s[j] == 'L') {
				map[i][j] = 1;
				V.push_back({ i,j });
			}
		}
	}
	printf("%d", Time(R, C));
}