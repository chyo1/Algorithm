class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size(), color[3] = {0, };
        vector <int> ans(size);

        for (int i = 0; i < size; i++)
            color[nums[i]]++;

        int idx = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < color[i]; j++)
                ans[idx++] = i;
        }
        nums = ans;
    }
};