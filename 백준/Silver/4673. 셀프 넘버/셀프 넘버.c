#include <stdio.h>
void Self_num();
int arr[10001] = { 0, };
int main() {
	int i;
	Self_num();
	for (i = 1; i <= 10000; i++) {
		if (!arr[i]) printf("%d\n", i);
	}

}
void Self_num() {
	int i, n, i_1000, i_100, i_10, i_1;

	for (i = 1; i <= 10000; i++) {
		i_1000 = i / 1000;
		i_100 = i / 100 - i_1000 * 10;
		i_10 = i / 10 - i_1000 * 100 - i_100 * 10;
		i_1 = i % 10;

		n = i + i_1000 + i_100 + i_10 + i_1;


		if (n <= 10000) arr[n]++; // 합이 10000 이하일 경우 배열에 저장
	}
}