#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, Max = 0;
int map[501][501];
bool visited[501][501];

void DFS(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		Max = Max > sum ? Max : sum;
		return;
	}

	int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

	for (int i = 0; i < 4; i++) {
		int nx = x + d[i][0], ny = y + d[i][1];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny]) continue;

		visited[nx][ny] = true;
		DFS(nx, ny, cnt + 1, sum + map[nx][ny]);
		visited[nx][ny] = false;
	}
}
void Tetro(int x, int y, int sum) {
	int d[4][3][2] = {
	{ {0,-1},{-1,0},{1,0} }, // ㅓ
	{ {0,1},{-1,0},{1,0} }, // ㅏ
	{ {-1,0},{0,-1},{0,1} }, // ㅗ
	{ {1,0},{0,-1},{0,1} }, // ㅜ
	};

	int s, i, j, nx, ny;

	for (i = 0; i < 4; i++) {
		s = sum;
		for (j = 0; j < 3; j++) {
			nx = x + d[i][j][0], ny = y + d[i][j][1];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;

			s += map[nx][ny];
		}
		Max = Max > s ? Max : s;
	}
}
void Find_Max() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;

			DFS(i, j, 1, map[i][j]);
			Tetro(i, j, map[i][j]);

			visited[i][j] = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) scanf("%d", &map[i][j]);
	}
	Find_Max();
	printf("%d", Max);
	return 0;
}