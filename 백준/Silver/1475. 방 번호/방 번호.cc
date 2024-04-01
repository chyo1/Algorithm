#include <stdio.h>
int main() {
	int N, num[10] = { 0, }, max = 0, max69;

	scanf("%d", &N);

	while (N > 0) {
		num[N % 10]++;
		N /= 10;
	}
    
	for (int i = 0; i < 10; i++) {
		if (i != 6 && i != 9) {
			if (max < num[i]) max = num[i];
		}
	}
	max69 = (num[6] + num[9]) / 2;
    
	if ((num[6] + num[9]) % 2) max69++;
	if (max < max69) max = max69;

	printf("%d", max);
	return 0;
}