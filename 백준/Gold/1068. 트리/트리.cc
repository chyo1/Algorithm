#include <stdio.h>
#include <vector>
using namespace std;
vector <int> V[51];
int del;
int Del(int r) {
	int child = 0;
	for (int i : V[r]) {
		if (i == del) continue;
		child += Del(i);
	}
	if (child) return child;
	else return 1;
}
int main() {
	int N, cnt = 0;
	int root;

	int parent;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &parent);
		if (parent == -1) root = i;
		else V[parent].push_back(i);
	}
	scanf("%d", &del);
	if (root == del) printf("0");
	else printf("%d", Del(root));

	return 0;
}