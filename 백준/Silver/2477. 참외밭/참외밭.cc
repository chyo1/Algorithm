#include <stdio.h>

int dir[6], len[6], D[5];

int Shape();
int get_Size(int);

int main() {
	int cnt, size, s, i;

	scanf("%d", &cnt);
	for (i = 0; i < 6; i++) {
		scanf("%d %d", &dir[i], &len[i]);
		D[dir[i]]++;
	}
	s = Shape();
	size = get_Size(s);

	printf("%d", size*cnt);
	return 0;
}
int Shape() {
	if (D[1] == 2) {
		if (D[3] == 2) return 4;
		else return 2;
	}
	if (D[2] == 2) {
		if (D[3] == 2) return 1;
		else return 3;
	}
}
int get_Size(int start) {
	int i, S, s;
	for (i = 0; i < 6; i++) {
		if (dir[i] == start) break;
	}
	S = len[i % 6] * len[(i + 1) % 6];
	s = len[(i + 3) % 6] * len[(i + 4) % 6];
	return S - s;
}