class Solution {
#define MAX_VAL 100'001
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen =  MAX_VAL, size = nums.size();
        
        int sum = 0, start = 0, end = 0;
        while (end < size) {
            sum += nums[end++];
            if (sum >= target) {
                while (sum - nums[start] >= target) {
                    sum -= nums[start];
                    start++;
                }
                minLen = min(minLen, end - start);
            }
        }

        return minLen == MAX_VAL ? 0 : minLen;
    } 
};