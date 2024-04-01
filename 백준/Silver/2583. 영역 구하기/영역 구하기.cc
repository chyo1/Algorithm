#include <stdio.h>
#include <queue>
#include <vector>
#include <stdlib.h>
using namespace std;
int map[101][101];
int M, N, K;
void color(int x1, int x2, int y1, int y2) {
	int i, j;
	for (i = x1; i < x2; i++) {
		for (j = y1; j < y2; j++) {
			map[i][j] = -1;
		}
	}
}
int BFS(int a, int b) {
	int x, y, nx, ny, i, size =0;
	int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

	queue <pair<int, int>> Q;

	Q.push({ a,b });
	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;		
		map[x][y] = 1;
		size++;
		Q.pop();
		for (i = 0; i < 4; i++) {
			nx = x + dx[i], ny = y + dy[i];
			if (0 <= nx && nx < M && 0 <= ny && ny < N && !map[nx][ny]) {
				map[nx][ny] = 1;
				Q.push({ nx,ny });
			}
		}
	}
	return size;
}
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int main() {
	int x1, y1, x2, y2;
	int i, j, cnt = 0, region[100];
	scanf("%d %d %d", &M, &N, &K);
	for (i = 0; i < K; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		color(y1, y2 , x1, x2);
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if (!map[i][j])
				region[cnt++] = BFS(i, j);
		}
	}
	qsort(region, cnt, sizeof(int), cmp);
	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++) printf("%d ", region[i]);
	return 0;
}