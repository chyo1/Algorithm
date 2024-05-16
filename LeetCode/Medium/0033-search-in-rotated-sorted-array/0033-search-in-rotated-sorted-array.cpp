class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start, end, minIdx;
        
        start = 0, end = nums.size() - 1;
        
        // 시작 지점 찾기
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] > nums[end])
                start = mid + 1;
            else
                end = mid;
        }
        minIdx = start;
        start = 0, end = nums.size() - 1;

        // 배열 시작, 끝 재지정
        if (nums[minIdx] <= target && target <= nums[end])
            start = minIdx;
        else
            end = minIdx - 1;
        
        // 이분탐색
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
};