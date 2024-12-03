class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start = 1, end = *max_element(nums.begin(), nums.end());

        int minPenalty = end;
        while (start <= end) {
            int penalty = start + (end - start) / 2;
            if (isPossible(nums, penalty, maxOperations)) {
                minPenalty = penalty, end = penalty - 1;
            }
            else
                start = penalty + 1;
        }
        return minPenalty;
    }

    bool isPossible(vector<int>& nums, int penalty, int maxOperations) {
        int totalOperations = 0;
        for (int n : nums) {
            int cnt = n / penalty;
            if (n % penalty == 0) cnt--;
            totalOperations += cnt;
        }
        return totalOperations <= maxOperations;
    }
};