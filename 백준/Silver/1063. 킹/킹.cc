#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

vector < pair<int, int>> V;
void P(int kx, int ky, int sx, int sy, int N) {
	int nx, ny;
	int nsx, nsy;
	for (int i = 0; i < N; i++) {
		nx = kx + V[i].first, ny = ky + V[i].second;
		nsx = sx + V[i].first, nsy = sy + V[i].second;

		if (0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
			if (nx == sx && ny == sy) {
				if (0 <= nsx && nsx < 8 && 0 <= nsy && nsy < 8) sx = nsx, sy = nsy, kx = nx, ky = ny;
			}
			else kx = nx, ky = ny;
		}
	}
	printf("%c%d\n%c%d", ky + 'A', 8 - kx, sy + 'A', 8 - sx);
}
int main() {
	char loc_k[3], loc_s[3], move[3];
	int N, Chess[8][8];

	scanf("%s %s %d", loc_k, loc_s, &N);


	for (int i = 0; i < N; i++) {
		scanf("%s", move);
		if (!strcmp(move, "R")) V.push_back({ 0,1 });
		else if (!strcmp(move, "L")) V.push_back({ 0,-1 });
		else if (!strcmp(move, "B")) V.push_back({ 1,0 });
		else if (!strcmp(move, "T")) V.push_back({ -1,0 });
		else if (!strcmp(move, "RT")) V.push_back({ -1,1 });
		else if (!strcmp(move, "LT")) V.push_back({ -1,-1 });
		else if (!strcmp(move, "RB")) V.push_back({ 1,1 });
		else if (!strcmp(move, "LB")) V.push_back({ 1,-1 });
	}

	P('8' - loc_k[1], loc_k[0] - 'A', '8' - loc_s[1], loc_s[0] - 'A', N);

	return 0;
}