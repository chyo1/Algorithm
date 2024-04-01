#include <vector>
#include <stdio.h>
using namespace std;

int main(void)
{
	int cnt = 0;
	char C[9];
	for (int i = 0; i < 8; i++) {
		scanf("%s", C);
		if (!(i % 2)) {
			for (int j = 0; j < 8; j += 2) {
				if (C[j] == 'F') cnt++;
			}
		}
		else {
			for (int j = 1; j < 8; j += 2) {
				if (C[j] == 'F') cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}