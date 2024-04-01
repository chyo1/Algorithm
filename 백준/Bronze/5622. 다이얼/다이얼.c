#include <stdio.h>
int main() {
	int sec[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
	int i = 0, time = 0;
	char number[16];
	scanf("%s", &number);
	while (number[i] != NULL) {
		time += sec[number[i] - 'A'];
		i++;
	}
	printf("%d", time);
	return 0;
}