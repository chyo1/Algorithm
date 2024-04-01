#include <stdio.h>
int cnt = 0;
void Get(long int N) {
	long int sum = 0;
	if (N < 10) {
		printf("%d\n", cnt);
		if (N % 3) printf("NO");
		else printf("YES");
		return;
	}
	while (N != 0) {
		sum += N % 10;
		N /= 10;
	}
	cnt++;
	Get(sum);
}

int main() {
	long int N = 0;
	int i = 0;
	char s[1000001];
	scanf("%s", s);
	while (s[i] != NULL) {
		N += s[i++] - '0';
	}
	if (i != 1) cnt++;
	Get(N);
	return 0;
}
