#include <stdio.h>
#include <vector>
using namespace std;

vector <int> V;
int N, M;

void Track(int cnt);
void init(int M);
void Print();

int main() {
	scanf("%d %d", &N, &M);
	Track(0);
	return 0;
}

void Track(int cnt) {
	if (cnt == M) {
		Print();
		return;
	}	
	for (int i = 1; i <= N; i++) {
		if (!V.empty() && V[V.size() - 1] > i) continue;
		V.push_back(i);
		Track(cnt + 1);
		V.pop_back();
	}
}
void Print() {
	for (int i = 0; i < V.size(); i++)
		printf("%d ", V[i]);
	printf("\n");
}