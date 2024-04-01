#include <stdio.h>
int height[257];
int N, M, B;
void Find(int min, int max) {
	int value = min - 1, high;
	int plus, del, time = 1000000000;

	while (value <= max) {
		value++;
		plus = del = 0;
		for (int i = min; i <= max; i++) {
			if (value - i > 0) plus += (value - i)*height[i];
			else del += (i - value)*height[i];
		}

		// 가지고 있는 블록 갯수보다 많을 때
		if (plus > B + del) continue;

		int t = del * 2 + plus;
		if (t < time) time = t, high = value;
		else if (t == time && high < value) high = value;
	}
	printf("%d %d", time, high);
}

int main() {
	int max = -1, min = 300, n;
	scanf("%d %d %d", &N, &M, &B);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &n);
			height[n]++;
			if (n < min) min = n;
			if (n > max) max = n;
		}
	}
	Find(min, max);
	return 0;
}