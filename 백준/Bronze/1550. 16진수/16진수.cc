#include <stdio.h>
#include <string.h>
int main() {
	char O[7];
	int mul = 1, sum = 0;
	scanf("%s", O);
	for (int i = strlen(O) - 1; i >= 0; i--) {
		if ('0' <= O[i] && O[i] <= '9') sum += mul * (O[i] - '0');
		else sum += mul * (10 + (O[i] - 'A'));
		mul *= 16;
	}
	printf("%d", sum);
	return 0;
}