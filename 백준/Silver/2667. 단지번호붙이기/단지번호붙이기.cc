#include <stdio.h>
#include <stdlib.h>
int map[26][26], visited[25][25];
int N, town = 0, house[625];
int cnt;
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };  // up down left right

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int DFS(int a, int b) {
	int i;
	if (a<0 || a>N || b<0 || b>N || !map[a][b] || visited[a][b] == 1) return 0;
	visited[a][b] = 1;
	cnt++;
	for (i = 0; i < 4; i++) DFS(a + di[i], b + dj[i]);
	return cnt;
}
int main() {
	int i, j, h = 0;
	char c;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%c", &c); // \n
		for (j = 0; j < N; j++) {
			scanf("%c", &c);
			map[i][j] = c - '0';
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				cnt = 0;
				house[h++] = DFS(i, j);
				town++;
			}
		}
	}
	if (h == 0) printf("0\n");
	else {
		qsort(house, h, sizeof(int), cmp);
		printf("%d\n", town);
		for (i = 0; i < town; i++) printf("%d\n", house[i]);
	}
	return 0;
}