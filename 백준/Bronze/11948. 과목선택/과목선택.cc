#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int score[6];
	for (int i = 0; i < 6; i++) scanf("%d", &score[i]);

	sort(score, score + 4);
	if (score[4] > score[5]) printf("%d", score[1] + score[2] + score[3] + score[4]);
	else printf("%d", score[1] + score[2] + score[3] + score[5]);

	return 0;
}