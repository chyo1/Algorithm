class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() <= 1)
            return 0;

        set<int> s;
        int start = 0, end = 0;

        sort(nums.begin(), nums.end());
        while (start < nums.size() && end < nums.size()) {
            int diff = nums[end] - nums[start];
            if (start == end){
                if (end < nums.size() - 1) end++;
                else start++;
                continue;
            }   
            if (diff == k)
                s.insert(nums[end]);

            if (end < nums.size() - 1 && diff <= k) end++;
            else start++;
        }
        return s.size();
    }
};
// 1 1 3 4 5