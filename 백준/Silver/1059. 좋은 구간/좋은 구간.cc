#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int L, S[50], n;
	int s, e, a, b;

	scanf("%d", &L);
	for (int i = 0; i < L; i++) scanf("%d", &S[i]);
	scanf("%d", &n);

	sort(S, S + L);

	if (n < S[0]) {
		s = 1, e = S[0] - 1;

		a = e - (n + 1) + 1;
		b = (n - 1) - s + 1;
		printf("%d", a*b + a + b);
		return 0;
	}
	for (int i = 0; i < L - 1; i++) {
		if (S[i] == n || S[i + 1] == n) break;
		if (S[i] < n&&n < S[i + 1]) {
			// 실제 범위
			s = S[i] + 1, e = S[i + 1] - 1;

			a = e - (n + 1) + 1;
			b = (n - 1) - s + 1;
			printf("%d", a*b + a + b);
			return 0;
		}
	}
	printf("0");
	return 0;
}