#include <stdio.h>
#include <queue>
using namespace std;

int B[31][31][31];
int L, R, C;
bool visited[31][31][31];
queue <pair<int, pair<int, int>>> Q;

bool Is_in(int l, int r, int c) {
	if (l < 0 || l >= L) return false;
	if (r < 0 || r >= R) return false;
	if (c < 0 || c >= C) return false;
	if (visited[l][r][c] || !B[l][r][c]) return false;
	return true;
}

void Escape() {
	int l, r, c, nl, nr, nc;
	int Cnt[31][31][31] = { 0, };
	int move[6][3] = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };

	while (!Q.empty()) {
		l = Q.front().first, r = Q.front().second.first, c = Q.front().second.second;
		Q.pop();

		for (int i = 0; i < 6; i++) {
			nl = l + move[i][0], nr = r + move[i][1], nc = c + move[i][2];

			// 갈 수 있는 경우
			if (Is_in(nl, nr, nc)) {

				// 도착지점
				if (B[nl][nr][nc] == -1) {
					printf("Escaped in %d minute(s).\n", Cnt[l][r][c] + 1);
					return;
				}

				visited[nl][nr][nc] = true;
				Q.push({ nl,{nr,nc} });
				Cnt[nl][nr][nc] = Cnt[l][r][c] + 1;
			}
		}
	}
	printf("Trapped!\n");
}
int main() {
	char c;

	// input
	while (1) {
		scanf("%d %d %d", &L, &R, &C);
		if (!L && !R && !C) return 0;

		else {
			for (int i = 0; i < L; i++) {
				c = getchar(); // \n

				for (int j = 0; j < R; j++) {
					for (int k = 0; k < C; k++) {
						scanf("%c", &c);

						if (c == 'S') {
							Q.push({ i,{j,k} });
							visited[i][j][k] = true;
						}
						if (c == '.') B[i][j][k] = 1;
						else if (c == 'E') B[i][j][k] = -1;
					}
					c = getchar(); // \n
				}
			}
		}
		Escape();

		// init
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++)
					B[i][j][k] = visited[i][j][k] = 0;
			}
		}
		while (!Q.empty()) Q.pop();
	}
}