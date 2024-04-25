class Solution {
public:
    int longestIdealString(string s, int k) {
        
        int dp[26] = {0, }, ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int dif = s[i] - 'a';

            int maxLen = 0;
            for (int j = 0; j < 26; j++) {
                if (abs(dif - j) <= k) {
                    maxLen = max(maxLen, dp[j]);
                }
            }

            dp[dif] = max(dp[dif], maxLen + 1);
            ans = max(ans, dp[dif]);
        }

        return ans;
    }
};