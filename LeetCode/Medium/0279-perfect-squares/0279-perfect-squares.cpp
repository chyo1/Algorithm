class Solution {
public:
    int numSquares(int n) {
        int dp[10001];
        fill(dp, dp + 10001, 10001);

        int num = 1;
        while (num * num <= n) {
            dp[num * num] = 1;
            num++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (dp[i] != 10001) continue;
            for (int j = 1; j * j <= i / 2; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + dp[j * j]);
            }
        }
        return dp[n];
    }
};
/*
dp[n] = dp[n-i] + dp[i];
dp[2] = dp[1] + dp[1];
dp[3] = dp[2] + dp[1];
dp[5] = dp[4] + dp[1] / dp[3] + dp[2]
dp[6] = dp[5] + dp[1] / dp[4] + dp[2] / dp[3] + dp[3]
*/