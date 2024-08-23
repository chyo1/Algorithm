class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < min1)
                min1 = nums[i];
            if (min1 < nums[i] && nums[i] < min2)
                min2 = nums[i];
            if (min2 < nums[i])
                return true;
        }
        return false;
    }
};