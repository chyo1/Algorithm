#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int map[50][50];
int visited[50][50];

queue <pair<int, int>> Q;
queue <pair<int, int>> P;

int N, L, R;

int SUM(int a, int b) {

	int x, y, nx, ny;
	int cnt = 0, diff, sum = map[a][b];
	int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
	visited[a][b] = 1;
	Q.push({ a,b });
	P.push({ a,b });
	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();
		
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i], ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[nx][ny]) {
				diff = abs(map[x][y] - map[nx][ny]);
				if (L <= diff && diff <= R) {
					visited[nx][ny] = 1;
					Q.push({ nx,ny });
					P.push({ nx,ny });
					sum += map[nx][ny];
					cnt++;
				}
			}
		}
	}
	sum /= P.size();
	if (P.size() == 1) P.pop();
	else {
		while (!P.empty()) {
			x = P.front().first;
			y = P.front().second;
			P.pop();
			map[x][y] = sum;
		}
	}
	return cnt;
}
int main() {

	int i, j, cnt = 1, day = 0;
	scanf("%d %d %d", &N, &L, &R);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) scanf("%d", &map[i][j]);
	}

	while (1) {
		cnt = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (!visited[i][j])
					cnt += SUM(i, j);
			}
		}
		if (cnt == 0) break;
		memset(visited, 0, sizeof(visited));
		day++;
	}
	printf("%d", day);
	return 0;
}