#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> V;
int N, M;
bool visited[9];

void Track(int cnt);
void init(int M);
void Print();

int main() {
	scanf("%d %d", &N, &M);
    fill(visited, visited + N+1, false);
	Track(0);
	return 0;
}

void Track(int cnt) {
	if (cnt == M){
		Print();
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			V.push_back(i);
			visited[i] = true;
			Track(cnt + 1);
			V.pop_back();
			visited[i] = false;
		}
	}
}
void Print() {
	for (int i = 0; i < V.size(); i++)
		printf("%d ", V[i]);
	printf("\n");
}