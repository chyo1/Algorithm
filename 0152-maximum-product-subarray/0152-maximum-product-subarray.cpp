class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxVal = INT_MIN;

        int subMul = 1;
        for (int i = 0; i < nums.size(); i++) {
            subMul *= nums[i];
            maxVal = max(maxVal, subMul);

            if (subMul == 0)
                subMul = 1;
        }

        subMul = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            subMul *= nums[i];
            maxVal = max(maxVal, subMul);

            if (subMul == 0)
                subMul = 1;
        }
        
        return maxVal;
    }
};