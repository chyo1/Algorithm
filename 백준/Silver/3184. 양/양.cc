#include <stdio.h>
#include <queue>
#include <vector>
#include <queue>
using namespace std;

int ground[251][251];
int sheep, wolf;
bool visited[251][251];
vector <pair<int, int>> V;

auto Morning(int R, int C) {
	int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
	int x, y, nx, ny, sh, wo;
	queue <pair<int, int>> Q;

	for (int v = 0; v < V.size(); v++) {
		x = V[v].first, y = V[v].second;
		if (visited[x][y]) continue;

		sh = wo = 0;
		Q.push({ x,y });
		visited[x][y] = true;
		if (ground[x][y] == 2) wo++;
		else if (ground[x][y] == 3) sh++;

		while (!Q.empty()) {
			x = Q.front().first, y = Q.front().second;
			Q.pop();
			for (int i = 0; i < 4; i++) {
				nx = x + d[i][0], ny = y + d[i][1];

				if (visited[nx][ny] || !ground[nx][ny] || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

				visited[nx][ny] = true;
				Q.push({ nx,ny });

				if (ground[nx][ny] == 2) wo++;
				else if (ground[nx][ny] == 3) sh++;
			}
		}

		if (sh > wo) wolf -= wo;
		else sheep -= sh;
	}
	printf("%d %d", sheep, wolf);
}

int main() {
	int R, C;
	char s[251];

	scanf("%d %d\n", &R, &C);

	sheep = wolf = 0;
	for (int i = 0; i < R; i++) {
		scanf("%s", s);
		for (int j = 0; j < C; j++) {
			if (s[j] != '#') V.push_back({ i,j });

			if (s[j] == '.') ground[i][j] = 1;
			else if (s[j] == 'v') {
				ground[i][j] = 2; // 늑대
				wolf++;
			}
			else if (s[j] == 'o') {
				ground[i][j] = 3; // 양
				sheep++;
			}
		}
	}
	Morning(R, C);
}