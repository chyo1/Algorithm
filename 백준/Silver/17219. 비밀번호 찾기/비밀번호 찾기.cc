#include <iostream>
#include <string>
#include <map>
using namespace std;

map <string,string> Site;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, loc;
	string A, B;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		Site.insert({ A,B });
	}

	for (int i = 0; i < M; i++) {
		cin >> A;

		auto idx = Site.find(A);
		cout << idx->second << '\n';
	}
	return 0;
}