#include <stdio.h>
#include <vector>
using namespace std;

vector <int> V;
int N, M;
bool visited[9];

void Track(int cnt);
void init(int M);
void Print();

int main() {
	scanf("%d %d", &N, &M);
	init(N);
	Track(0);
	return 0;
}

void Track(int cnt) {
	if (cnt == M) {
		Print();
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		if (!V.empty()) {
			if (V[V.size() - 1] > i) continue;
		}
		V.push_back(i);
		visited[i] = true;
		Track(cnt + 1);
		V.pop_back();
		visited[i] = false;
	}
}
void init(int N) {
	for (int i = 0; i <= N; i++)
		visited[i] = false;
}
void Print() {
	for (int i = 0; i < V.size(); i++)
		printf("%d ", V[i]);
	printf("\n");
}