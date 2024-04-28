class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int size  = nums.size() / 2, idx = size;
        while (size > 0) {

            if (idx % 2)
                idx++;
            if (size % 2 && size != 1)
                size++;
            // printf("idx : %d nums[idx] : %d size : %d\n", idx, nums[idx], size);

            // 답이 현재 idx 앞에 존재
            if (nums[idx] == nums[idx - 1])
                idx -= size / 2;
            
            // 답이 현재 idx 뒤에 존재
            else if (nums[idx] == nums[idx + 1])
                idx += size / 2;

            // 현재 idx 가 답
            else
                return nums[idx];
            size /= 2;
        }
        return nums[0];
    }
};
