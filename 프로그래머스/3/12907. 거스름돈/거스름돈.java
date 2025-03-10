import java.util.*;

class Solution {
    private int DIV = 1_000_000_007;
    public int solution(int n, int[] money) {
        int len = money.length;
        int[][] dp = new int[len + 1][n + 1];
        
        for (int i = 1; i <= len; i++) {
            int coin = money[i - 1];
            for (int j = 0; j <= n; j++) {
                if (j == 0) dp[i][j] = 1;
                else if (j < coin) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = (dp[i - 1][j] + dp[i][j - coin]) % DIV;
                
            }
        }
        return dp[len][n];
    }
}