#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

bool map[50][50];

int Find(int n) {
	int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
	int x, y, cnt, nx, ny;
	int visited[50][50];
	queue <pair<pair<int, int>, int>> Q;

	fill(visited[0], visited[50], 10000);
	Q.push({ { 0,0 }, 0 });
	visited[0][0] = 0;
	while (!Q.empty()) {
		x = Q.front().first.first, y = Q.front().first.second, cnt = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			nx = x + d[i][0], ny = y + d[i][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] <= cnt) continue;

			if (map[nx][ny] == false) {
				visited[nx][ny] = cnt + 1;
				Q.push({ {nx,ny},cnt + 1 });
			}
			else {
				visited[nx][ny] = cnt;
				Q.push({ {nx,ny},cnt });
			}
		}
	}
	return visited[n - 1][n - 1];
}
int main() {
	int n;
	char s[51];
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int j = 0; j < n; j++) map[i][j] = s[j]-'0';
	}
	printf("%d", Find(n));
	return 0;
}