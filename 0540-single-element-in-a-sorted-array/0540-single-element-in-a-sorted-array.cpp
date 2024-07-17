class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int idx = (start + end) / 2;

            // 답이 현재 idx 뒤에 존재
            if ((idx % 2 && nums[idx] == nums[idx - 1]) || (!(idx % 2) && nums[idx + 1] == nums[idx]))
                start = idx + 1;
               
            // 답이 현재 idx 앞에 존재 or 현재 idx
            else end = idx;
        }
        return nums[start];
    }
};