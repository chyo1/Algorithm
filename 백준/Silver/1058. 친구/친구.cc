#include <stdio.h>
bool F[50][50], visited[50][50];

int Friend(int now, int N) {
	int max = 0, cnt;
	for (int i = 0; i < N; i++) {
        cnt = 0;
		for (int j = 0; j < N; j++) {
			if (F[i][j]) {
				visited[i][j] = true;
				for (int k = 0; k < N; k++) {
					if (F[j][k]&&i!=k) visited[i][k] = true;
				}
			}
		}
        
        for (int j = 0; j < N; j++) {
			if (visited[i][j]) cnt++;
		}
        if (max < cnt) max = cnt;
	}
	return max;
}
int main() {
	int N;
	char c[51];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", c);
		for (int j = 0; j < N; j++) {
			if (c[j] == 'Y') F[i][j] = visited[i][j] = true;
		}
	}
	printf("%d",Friend(0,N));
	return 0;
}