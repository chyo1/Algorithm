#include <vector>
#include <stdio.h>
using namespace std;

vector <int> V;
void Postorder(int start, int end) {
	if (start >= end) return;

	int i;
	for (i = start + 1; i < end; i++) {
		if (V[start] < V[i]) break;
	}

	Postorder(start + 1, i);
	Postorder(i, end);
	printf("%d\n", V[start]);
}
int main(void)
{
	int n;

	while (scanf("%d", &n) == 1)
		V.push_back(n);

	Postorder(0, V.size());
	return 0;
}