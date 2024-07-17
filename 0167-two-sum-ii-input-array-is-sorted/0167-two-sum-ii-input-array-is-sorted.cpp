class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int start = 0, end = numbers.size() - 1;
        while (1) {
            int sum = numbers[start] + numbers[end];
            if (sum == target)
                break;
            else if (sum < target)
                start++;
            else
                end--;
        }
        return vector<int> {start + 1, end + 1};
    }
};