#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector <pair<int, int>> V;

int map[101][101];
bool visited[101][101];
int N, M, K;
int cnt;

void Find(int x, int y) {
	int nx, ny;
	int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

	for (int i = 0; i < 4; i++) {
		nx = x + dx[i], ny = y + dy[i];
		if (1 <= nx && nx <= N && 1 <= ny && ny <= M && !visited[nx][ny] && map[nx][ny]) {
			visited[nx][ny] = 1;
			cnt++;
			Find(nx, ny);
		}
	}
}

int main() {
	int x, y, max = 0;
	scanf("%d %d %d", &N, &M, &K);
	for (int k = 0; k < K; k++) {
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
		V.push_back({ x,y });
	}
	for (int i = 0; i < V.size(); i++) {
		cnt = 0;
		x = V[i].first, y = V[i].second;
		if (!visited[x][y]) {
			Find(x, y);
			max = max > cnt ? max : cnt;
		}
	}
	printf("%d", max);
	return 0;
}