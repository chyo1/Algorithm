#include <stdio.h>
#include <algorithm>

using namespace std;
#define MAX 1000002
#define SIZE 1000001

int total[SIZE];
int F, S, G, U, D;
bool end_flag;

void get_minimum_time(int now, unsigned int time) {
	total[now] = time;
	if (now + U <= F && total[now + U] > time + 1)
		get_minimum_time(now + U, time + 1);
	if (now - D >= 1 && total[now - D] > time + 1)
		get_minimum_time(now - D, time + 1);
}

int main(){
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	fill(total, total + SIZE, MAX);
	if (S == G) {
		printf("0");
		return 0;
	}
	get_minimum_time(S,0);
	if (total[G] < MAX)
		printf("%d", total[G]);
	else
		printf("use the stairs");
	return 0;
}