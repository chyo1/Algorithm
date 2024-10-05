#include <climits>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    int dp[1'000'001] = {0, };
    queue <int> q;
    
    if (x == y) return 0;
    
    dp[x] = 1;
    q.push(x);
    
    while (!q.empty()) {
        int now = q.front(), cnt = dp[now] + 1;
        q.pop();
        
        if (now == y)
            return dp[now] - 1;
        
        if (now + n <= y && dp[now + n] == 0) {
            dp[now + n] = cnt;
            q.push(now + n); 
        }
        
        if (now * 2 <= y && dp[now * 2] == 0) {
            dp[now * 2] = cnt;
            q.push(now * 2);
        }
        
        if (now * 3 <= y && dp[now * 3] == 0) {
            dp[now * 3] = cnt;
            q.push(now * 3);
        }
    }
    return -1;
}