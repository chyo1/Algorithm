#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

queue <pair<int, int>> Q;
int map[100][100], visited[100][100];
int N;

void BFS(int h, int x, int y);
int main() {

	int i, j, k;
	int max = 0, min = 101;
	int cnt, M = 1;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			min = min < map[i][j] ? min : map[i][j];
			max = max > map[i][j] ? max : map[i][j];
		}
	}
	for (k = min; k < max; k++) {
		cnt = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (map[i][j] > k && !visited[i][j]) {
					BFS(k, i, j);
					cnt++;
				}
			}
		}
		if (cnt > M) M = cnt;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				visited[i][j] = 0;
			}
		}
	}
	printf("%d", M);
	return 0;
}
void BFS(int h, int x, int y) {
	int di[4] = { -1,1,0,0 };
	int dj[4] = { 0,0,-1,1 };
	int nx, ny, i;
	visited[x][y] = 1;
	Q.push({ x,y });
	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();
		for (i = 0; i < 4; i++) {
			nx = x + di[i], ny = y + dj[i];
			if (0 <= nx && nx < N && 0 <= ny && ny<N&&map[nx][ny] > h && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				Q.push({ nx,ny });
			}
		}
	}
}