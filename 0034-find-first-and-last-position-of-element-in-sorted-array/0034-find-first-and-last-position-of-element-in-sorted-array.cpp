class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) 
            return {-1, -1};

        int start = 0, mid, end = nums.size() - 1;

        while (start <= end) {
            mid = (start + end) / 2;

            if (nums[mid] == target)
                break;
            if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }

        if (nums[mid] != target)
            return {-1, -1};

        start = end = mid;
        while (0 <= start && nums[start] == target)
            start--;

        while (end < nums.size() && nums[end] == target)
            end++;

        return {start + 1, end - 1};
    }
};