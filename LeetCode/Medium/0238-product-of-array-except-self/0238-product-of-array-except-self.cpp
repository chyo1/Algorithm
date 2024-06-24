class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1, size = nums.size();
        vector<int> answer(size, 0);
        int zeroFlag = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0)
                zeroFlag++;
            else
                mul *= nums[i];
        }
        if (zeroFlag > 1)
            return answer;

        for (int i = 0; i < size; i++) {
            if (!nums[i]) {
                answer[i] = mul;
                continue;
            }
            if (!zeroFlag)
                answer[i] = mul / nums[i];
        }
        return answer;
    }
};