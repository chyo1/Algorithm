#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
int main() {
	double R, S1, S2, pie = 3.141593;
	scanf("%lf", &R);
	S1 = R * R*M_PI;
	R *= sqrt(2);
	S2 = R * R;
	printf("%.6f\n%.6f", S1, S2);
	return 0;
}