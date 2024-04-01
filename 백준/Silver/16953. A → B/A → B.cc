#include <stdio.h>
int min = 0;
void Cal(long int now, int end, int cnt) {
	if (now == end) {
		if (!min) min = cnt;
		else if (cnt < min) min = cnt;
		return;
	}
	if (now * 2 <= end) Cal(now * 2, end, cnt + 1);
	if (now * 10 + 1 <= end) Cal(now * 10 + 1, end, cnt + 1);

	if (cnt == 1 && !min) min = -1;
}

int main() {
	int A, B;
	scanf("%d %d", &A, &B);
	Cal(A, B, 1);
	printf("%d", min);
	return 0;
}