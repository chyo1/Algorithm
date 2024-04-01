#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

queue <pair<int, int>> Q;
int Cheese[100][100], visited[100][100];
int R, C;
int Is_melting(int a, int b) {
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int x, y, nx, ny, cnt = 0;

	Q.push({ a,b });
	while (!Q.empty()) {

		x = Q.front().first;
		y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			nx = x + dx[i], ny = y + dy[i];
			if (0 <= nx && nx < R && 0 <= ny && ny < C && !visited[nx][ny]) {
				if (!Cheese[nx][ny]) Q.push({ nx,ny });
				else {
					Cheese[nx][ny] = 0;
					cnt++;
				}
				visited[nx][ny] = 1;
			}
		}
	}
	return cnt;
}
int main() {
	int i, j;
	int day = 0, cnt, cheese;
	scanf("%d %d", &R, &C);

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) scanf("%d", &Cheese[i][j]);
	}

	while (1) {
		cnt = Is_melting(0, 0);		
		if (cnt != 0) cheese = cnt;
		else break;
		day++;
		memset(visited, 0, sizeof(visited));
	}

	printf("%d\n%d", day, cheese);
	return 0;
}