#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
queue <int> Q;
int box[100][100][100];
int M, N, H;
int cnt = 0;

int BFS();
int main() {

	int i, j, k;
	scanf("%d %d %d", &M, &N, &H);

	for (k = 0; k < H; k++) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				scanf("%d", &box[k][i][j]);
				if (!box[k][i][j]) cnt++;
				else if (box[k][i][j] == 1) {
					Q.push(k);
					Q.push(i);
					Q.push(j);
				}
			}
		}
	}
	if (!cnt) printf("0");
	else printf("%d", BFS() - 1);
	return 0;
}
int BFS() {
	int x, y, z;
	int nx, ny, nz;
	int max = 0;
	int dz[6] = { -1,1,0,0,0,0 };
	int dx[6] = { 0,0,-1,1,0,0 };
	int dy[6] = { 0,0,0,0,-1,1 };  // front back up down left right
	
	while (!Q.empty()) {
		z = Q.front();	Q.pop();
		x = Q.front();	Q.pop();
		y = Q.front();	Q.pop();
		for (int i = 0; i < 6; i++) {
			nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
			if ((0 <= nz && nz < H) && (0 <= nx && nx < N) && (0 <= ny && ny < M) && !box[nz][nx][ny]) {
				box[nz][nx][ny] = box[z][x][y]+1;
				if (max < box[nz][nx][ny]) max = box[nz][nx][ny];
				cnt--;
				Q.push(nz);	Q.push(nx);	Q.push(ny);
			}
		}
	}
	if (cnt) return 0;
	else return max;
}