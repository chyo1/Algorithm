class Solution {
public:
    bool visited[1'000'000];
    int dfs(vector<int>& nums, int now, int nowDepth) {
        visited[now] = true;

        if (visited[nums[now]]) return nowDepth;

        return dfs(nums, nums[now], nowDepth + 1);
    }

    int arrayNesting(vector<int>& nums) {
        int maxLen = 1;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (!visited[num]) {
                if (num == i)
                    visited[i] = true;
                else
                    maxLen = max(maxLen, dfs(nums, num, 1));
            }
        }
        return maxLen;
    }
};