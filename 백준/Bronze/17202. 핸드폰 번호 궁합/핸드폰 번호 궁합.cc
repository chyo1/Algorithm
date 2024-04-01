#include <stdio.h>
int main() {
	int i, j;
	char c;
	int match[15], num_1[8], num_2[8];
	for (i = 0; i < 8; i++) {
		scanf("%c", &c);
		num_1[i] = c - '0';
	}
	scanf("%c", &c); //\n
	for (i = 0; i < 8; i++) {
		scanf("%c", &c);
		num_2[i] = c - '0';
	}

	for (i = 0; i < 15; i += 2) {
		match[i] = (num_1[i / 2] + num_2[i / 2]) % 10;
		match[i + 1] = (num_2[i / 2] + num_1[i / 2 + 1]) % 10;
	} // 초기화

	for (i = 0; i < 13; i++) {
		for (j = 0; j < 13 - (i - 1); j++) match[j] = (match[j] + match[j + 1]) % 10;
	}
	printf("%d%d", match[0], match[1]);
	return 0;
}