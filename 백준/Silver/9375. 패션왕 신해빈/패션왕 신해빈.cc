#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector <pair<string, string>> V;
bool cmp(pair<string, string> a, pair<string, string> b) { return a.first < b.first; }
auto D() {
	string s = V[0].first;
	int cnt = 1, sec = 1;
	long long int d = 1;
	for (int i = 1; i < V.size(); i++) {
		if (s == V[i].first) cnt++;
		else {
			d *= (cnt + 1);
			cnt = 1;
			s = V[i].first;
			sec++;
		}
	}
	if (sec > 1) d = d * (cnt + 1) - 1;
	else d = cnt;
	return d;
}

int main() {
	int T, n;
	char name[21], sect[21];
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s %s", name, sect);
			V.push_back({ sect, name });
		}
		if (n == 0) printf("0\n");
		else {
			sort(V.begin(), V.end(), cmp);
			printf("%lld\n", D());
		}
		V.clear();
	}
	return 0;
}