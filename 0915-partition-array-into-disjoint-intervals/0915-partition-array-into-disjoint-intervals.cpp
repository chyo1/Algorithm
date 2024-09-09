class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int localMax = nums[0], totalMax = localMax, partitionIdx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < localMax) {
                localMax = totalMax;
                partitionIdx = i;
            }
            else totalMax = max(totalMax, nums[i]);
        }
        return partitionIdx + 1;
    }
};