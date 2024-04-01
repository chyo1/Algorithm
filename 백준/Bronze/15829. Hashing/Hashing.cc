#include <stdio.h>
int main() {
	int L, r = 31, M = 1234567891;
	unsigned long long result = 0, cal = 1;
	char c;
	scanf("%d\n", &L);
	for (int i = 0; i < L; i++) {
		scanf("%c", &c);
		result = (result + (c - 'a' + 1)*cal) % M;
		cal = (cal * 31) % M;
	}
	printf("%d", result);
	return 0;
}