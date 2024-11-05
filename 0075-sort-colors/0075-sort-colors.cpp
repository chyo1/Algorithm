class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colors[3] = {0, };
        for (int n : nums)
            colors[n]++;

        int idx = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < colors[i]; j++)
                nums[idx++] = i;
        }
    }
};