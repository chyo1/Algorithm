#include <stdio.h>
int main() {
	int N, num[100], v, cnt=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &num[i]);
	scanf("%d", &v);
	for (int i = 0; i < N; i++) {
		if (num[i] == v) cnt++;
	}
	printf("%d", cnt);
	return 0;
}