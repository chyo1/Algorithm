#include <stdio.h>
int main() {
	int num, i, cnt = 0, arr[42] = { 0, };
	for (i = 0; i < 10; i++) {
		scanf("%d", &num);
		arr[num % 42]++;
	}
	for (i = 0; i < 42; i++) {
		if (arr[i] != 0) cnt++;
	}
	printf("%d", cnt);
}