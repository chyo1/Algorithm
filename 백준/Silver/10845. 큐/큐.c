#include <stdio.h>
#include <string.h>
int num[10000];
int start = 0, end = 0;
void PUSH() {
	scanf("%d", &num[end++]);
}
void POP() {
	if(end-start>0) printf("%d\n", num[start++]);
	else printf("-1\n");
}
void SIZE() {
	printf("%d\n", end-start);
}
void EMPTY() {
	if (start == end) printf("1\n");
	else printf("0\n");
}
void FRONT() {
	if (end - start > 0) printf("%d\n", num[start]);
	else printf("-1\n");
}
void BACK() {
	if (end - start > 0) printf("%d\n", num[end-1]);
	else printf("-1\n");
}
int main() {
	int N, i, j = 0;
	char CMD[6];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", CMD);
		if (!strcmp(CMD, "push")) PUSH();
		else if (!strcmp(CMD, "pop")) POP();
		else if (!strcmp(CMD, "size"))	SIZE();
		else if (!strcmp(CMD, "empty")) EMPTY();
		else if (!strcmp(CMD, "front")) FRONT();
		else if (!strcmp(CMD, "back")) BACK();
	}
	return 0;
}