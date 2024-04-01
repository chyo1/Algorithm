#include <stdio.h>
#include <queue>
using namespace std;
priority_queue <pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
int main() {
	int N, x,y;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		Q.push({ x,y });
	}
	for (int i = 0; i < N; i++) {
		int tx, ty;
		tx = Q.top().first, ty = Q.top().second;
		printf("%d %d\n", tx, ty);
		Q.pop();
	}
	return 0;
}