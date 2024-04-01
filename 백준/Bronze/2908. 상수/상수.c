#include <stdio.h>
#include <math.h>
int main() {
	int n1 = 0, n2 = 0;
	char num1[4], num2[4], max[4];
	scanf("%s %s", num1, num2);
	int i;
	for (i = 2; i >= 0; i--) {
		n1 += (num1[i]-'0') * pow(10, i);
		n2 += (num2[i]-'0') * pow(10, i);
	}
	if (n1 > n2) printf("%d", n1);
	else printf("%d", n2);
	return 0;
}