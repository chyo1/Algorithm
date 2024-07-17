class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int start = 0, end = numbers.size() - 1;
        while (1) {
            int sum = numbers[start] + numbers[end];
            if (sum == target) {
                // if (start != end)
                //     break;
                // if (start > 0 && numbers[start - 1] + numbers[end] == target) {
                //     start--;
                //     printf("start\n");
                // }
                // else if (end < numbers.size() - 1 && numbers[start] + numbers[end + 1] == target) {
                //     end++;
                //     printf("end\n");
                // }
                // else {
                //     start--; end++;
                //     printf("other\n");
                // }
                // if (numbers[start] + numbers[end] == sum)
                    break;
            }
            else if (sum < target)
                start++;
            else
                end--;
        }
        // printf("%d %d\n", numbers[start], numbers[end]);
        ans[0] = start + 1, ans[1] = end + 1;
        // sort(ans.begin(), ans.end());
        return ans;
    }
};