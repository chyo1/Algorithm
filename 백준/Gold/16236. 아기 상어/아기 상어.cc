#include <stdio.h>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;


int map[21][21];
int N, shark = 2;

// int mark = 0, M[21][21] = { 0, }; 

pair<int,pair<int, int>> BFS(int x, int y) {

	bool visited[21][21] = { false, };
	int d[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };
	int nx, ny, cnt;

	// init
	priority_queue<  pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> Ans;
	queue<pair<int, pair<int, int>>> Q;
	Q.push({ 1,{ x,y } });
	visited[x][y] = true;

	while (!Q.empty()) {
		x = Q.front().second.first, y = Q.front().second.second, cnt = Q.front().first;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			nx = x + d[i][0], ny = y + d[i][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] || map[nx][ny] > shark) continue;

			visited[nx][ny] = true;

			if (map[nx][ny] && map[nx][ny] < shark) Ans.push({ cnt,{ nx,ny } });
			else Q.push({ cnt + 1,{ nx,ny } });
		}
	}
	Ans.push({ 1000,{ 100,100 } });
	return Ans.top();
}

int Eat(int x, int y) {
	int move = 0, cnt = 0;
	int nx, ny;
	pair<int, pair<int, int>> loc;

	while (1) {
		loc = BFS(x, y);
		nx = loc.second.first, ny = loc.second.second;
		if (nx == 100 && ny == 100) return move;

		move += loc.first;
		cnt++;
		map[nx][ny] = 0;

		if (cnt == shark) shark++, cnt = 0;

		x = nx, y = ny;

		// M[nx][ny] = ++mark; 
	}
}

int main() {
	int sx, sy;

	// input
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) sx = i, sy = j, map[i][j] = 0;
		}
	}
	printf("%d\n", Eat(sx, sy));

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) printf("%d ", M[i][j]);
		printf("\n");
	}
	*/
	return 0;
}