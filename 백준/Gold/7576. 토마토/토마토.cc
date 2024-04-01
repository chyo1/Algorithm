#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
queue <pair<int, int>> Q;

int M, N;
int box[1000][1000];

int BFS(int);
int main() {

	int i, j, cnt = 0;
	scanf("%d %d", &M, &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1) Q.push({ i,j });
			else if (!box[i][j]) cnt++; 
		}
	}
	if (!cnt) printf("0"); // 익지 않은 토마토가 없을 때
	else printf("%d", BFS(cnt) - 1);
	return 0;
}
int BFS(int count) {
	int x, y, nx, ny;
	int i, max = 0;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();
		for (i = 0; i < 4; i++) {
			nx = x + dx[i], ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && !box[nx][ny]) {
				Q.push({ nx,ny });
				box[nx][ny] = box[x][y] + 1;
				if (max < box[nx][ny]) max = box[nx][ny];
				count--;
			}
		}
	}
	if (count) return 0; // 익지 않은 토마토가 있는 지 확인
	return max;
}