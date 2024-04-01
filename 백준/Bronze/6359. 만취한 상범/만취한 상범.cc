#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int T, n;
	bool room[101] = { false, };
    
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &n);
        
		fill(room, room + n + 1, false);		
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= n; j += i) {
				room[j] = !room[j];
			}
		}
        
        int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!room[i]) cnt++;
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}