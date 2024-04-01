#include <stdio.h>
#define MAX_STACK_SIZE 50
typedef int element;

element stack[MAX_STACK_SIZE];
int top = -1;
int is_empty();
int is_full();
void push(element item);
element pop();
int main() {
	int num, cnt = 1;
	char bnk;
	scanf("%d\n", &num);
	while (num--) {
		top = -1, cnt = 1;
		while ((bnk = getchar()) != '\n') {
			if (bnk == '(') push(bnk);
			else if (bnk == ')') {
				if (!is_empty()) pop();
				else {
					//printf("NO\n");
					while ((bnk = getchar()) != '\n');
					cnt = 0;
					break;
				}
			}
		}
		if (is_empty() && cnt)	printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
int is_empty() {

	return (top == -1);
}
int is_full() {

	return (top == (MAX_STACK_SIZE - 1));
}
void push(element item) {

	stack[++top] = item;
}
element pop() {
	if (is_empty()) return 0;
	return stack[top--];
}