#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int in, out, ans = 0, now = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &out, &in);
		now += in - out;
		ans = max(ans, now);
	}
	printf("%d", ans);
	return 0;
}