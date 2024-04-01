#include <stdio.h>
int main() {
	int H, M, min;
	scanf("%d%d", &H, &M);
	min = M - 45;
	if (min < 0) {
		min += 60;
		if (!H) H = 23;
		else H -= 1;		
	}
	printf("%d %d", H, min);
}