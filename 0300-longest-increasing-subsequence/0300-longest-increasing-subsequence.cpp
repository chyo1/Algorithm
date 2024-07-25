class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size(), maxLen = 0;
        int dp[2500];

        for (int i = 0; i < size; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};