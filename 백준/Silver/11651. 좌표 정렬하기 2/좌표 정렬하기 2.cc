#include <stdio.h>
#include <queue>
using namespace std;
struct cmp {
	bool operator()(pair<int, int>a, pair <int, int> b) {
		if (a.second == b.second)
			return a.first > b.first;
		else return a.second > b.second;
	}
};
priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> Q;
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