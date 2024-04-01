#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
	char S[10][7] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
	char s1[7], s2[7], s3[7];
	long int R = 0;
	scanf("%s %s %s", s1, s2, s3);
	for (int i = 0; i < 10; i++) {
		if (strcmp(s1, S[i]) == 0) R += i * 10;
		if (strcmp(s2, S[i]) == 0) R += i;
	}
	for (int i = 0; i < 10; i++) {
		if (strcmp(s3, S[i]) == 0) R *= pow(10, i);
	}
	printf("%ld", R);
	return 0;
}