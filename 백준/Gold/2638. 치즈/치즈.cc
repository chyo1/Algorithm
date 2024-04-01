#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector <pair<int, int>> V;
queue <pair<int, int>> Q;
int map[101][101];
bool visited[101][101];
int N, M;

void Is_Melting(int x, int y) {
	int i, nx, ny, cnt = 0;
	int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
	for (i = 0; i < 4; i++) {
		nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M && visited[nx][ny] && !map[nx][ny])
			cnt++;
	}
	if (cnt >= 2) V.push_back({ x,y });
}
void Air() {
	int i, x, y, nx, ny;
	int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
	Q.push({ 0,0 });
	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;		
		Q.pop();
		for (i = 0; i < 4; i++) {
			nx = x + dx[i], ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && !map[nx][ny] && !visited[nx][ny]) {
				Q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
}
int Update() {
	int x, y, size;
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (map[i][j]) Is_Melting(i, j);
		}
	}
	size = V.size();
	for (i = 0; i < V.size(); i++) {
		x = V[i].first;
		y = V[i].second;
		map[x][y] = 0;
	}
	V.clear();
	return size;
}
int main() {

	int time = 0, size;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (1) {
		Air();
		size = Update();
		if (!size) break;
		memset(visited, false, sizeof(visited));
		time++;
	}
	printf("%d", time);
	return 0;
}