#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main(){
	int L, K;
	string id;
	vector<string> V, P;
	set<string> S;

	cin >> K >> L;
	for(int i = 0; i < L; i++)
	{
		cin >> id;
		V.push_back(id);
	}
	for(int i = V.size() - 1; i >= 0; i--)
	{
		if (S.insert(V[i]).second == 1)	
			P.push_back(V[i]);
	}
	int start = P.size() - 1;
	for(int i=0; i < K && i <= start; i++)
		cout << P[start - i] << '\n';
}