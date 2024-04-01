#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
set <int> S;
int map[5][5];

void Get_Number(int x, int y, int num, int cnt) {
	if (cnt == 6) {
		S.insert(num);
		return;
	}

	int nx, ny;
	int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

	for (int i = 0; i < 4; i++) {
		nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5)
			Get_Number(nx, ny, num * 10 + map[nx][ny], cnt + 1);
	}

}
int main() {
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++)
			scanf("%d", &map[i][j]);
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			Get_Number(i, j, map[i][j], 1);
		}
	}
	printf("%d", S.size());
	return 0;
}