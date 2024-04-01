#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> Card;
vector <pair<int, int>> Com;
int N, M;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
bool ret(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
void Is_in(int size) {
	int n1, n2;
	n1 = n2 = 0;
	while (n1 < N && n2 < M) {
		if(n1>=N||n2>=M) break;
		if (Card[n1] == Com[n2].second) {
			Com[n2].second = 1;
			n2++;
		}
		else if (Card[n1] > Com[n2].second) {
			Com[n2].second = 0;
			n2++;
		}
		else n1++;
	}
	if (n2 != M) {
		for (int i = n2; i < M; i++) Com[i].second = 0;
	}
}

int main() {
	int c;
	scanf("%d", &N); // num of disk
	for (int i = 0; i < N; i++) {
		scanf("%d", &c);
		Card.push_back(c);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &c);
		Com.push_back({ i,c });
	}
	sort(Card.begin(), Card.end());
	sort(Com.begin(), Com.end(), cmp);

	Is_in(M);
	sort(Com.begin(), Com.end(), ret);

	for (int i = 0; i < Com.size(); i++) printf("%d ", Com[i].second);

	return 0;
}