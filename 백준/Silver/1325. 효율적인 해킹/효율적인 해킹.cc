#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

vector <int> V[10001];
vector <int> P;
bool visited[10001];

int Find(int s) {
	int cnt = 0;
	visited[s] = true;
	for (int i : V[s])
		if(!visited[i]) cnt += Find(i) + 1; 
	return cnt;
}
int main() {
	int N, M;
	int A, B;
	int max = 0;
	int cnt;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &A, &B);
		V[B].push_back(A);
	}
	for (int i = 1; i <= N; i++) {
		cnt = Find(i);
		if (max < cnt) {			
			max = cnt;
			P.clear();
			P.push_back(i);
		}
		else if(max==cnt) P.push_back(i);

		memset(visited, false, sizeof(bool)*(N+1));
	}

	for (int i = 0; i < P.size(); i++) printf("%d ", P[i]);
	return 0;
}