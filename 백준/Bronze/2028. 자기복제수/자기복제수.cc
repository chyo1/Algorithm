#include <stdio.h>
bool Copy(int n) {
	int Pow = n * n;

	while (n != 0) {
		if (n % 10 != Pow % 10) return false;
		n /= 10, Pow /= 10;
	}
	return true;
}
int main() {
	int T, N;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);

		if (Copy(N)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}