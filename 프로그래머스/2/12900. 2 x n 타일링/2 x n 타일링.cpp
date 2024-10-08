#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int dp[60001] = {0, 1, 2};
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 2] + dp[i - 1]) %  1'000'000'007;
    
    return dp[n];
}