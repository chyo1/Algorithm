class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        int dp[101] = {0, };

        for (int i = 0; i < size; i++) {
            if (i == 0)
                dp[0] = nums[0];
            else if (i == 1)
                dp[1] = max(dp[0], nums[1]);
            else
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[size - 1];
    }
};