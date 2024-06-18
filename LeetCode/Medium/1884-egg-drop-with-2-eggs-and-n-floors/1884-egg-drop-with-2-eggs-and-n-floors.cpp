class Solution {
#define MAX_VAL 10000 //
public:
    int twoEggDrop(int n) {
        int dp[1001] = {1, };
        int maxCnt = 0;

        fill(dp, dp + 1001, MAX_VAL); //

        dp[0] = dp[n] = 1; //
        int step = 0, i = n;
        while (i > 0) {
            dp[i] = step + 1;
            i -= ++step;
        }
        // for (int i = 0; i <= n; i++)
        //     printf("%d ", dp[i]);
        return step;
    }
};