class Solution {
public:
    bool visited[1'000'000];
    int depth[1'000'000];
    int dfs(vector<int>& nums, int now, int nowDepth) {
        visited[now] = true;

        if (visited[nums[now]]) return nowDepth;
        
        depth[now] = dfs(nums, nums[now], nowDepth + 1);
        return depth[now];
    }

    int arrayNesting(vector<int>& nums) {
        int maxLen = 1;
        for (int num : nums) {
            if (!visited[num])
                maxLen = max(maxLen, dfs(nums, num, 1));
        }
        return maxLen;
    }
};