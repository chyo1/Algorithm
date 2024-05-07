class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, i = 0;
        int size = nums.size();

        if (size < 3)
            return 0;
        
        while (i < size - 2){
            if (nums[i] - nums[i + 1] == nums[i + 1] - nums[i + 2]) {
                int diff = nums[i] - nums[i + 1];
                i += 2;

                int cnt = 3;
                while (i + 1 < size && diff == nums[i] - nums[i + 1]){
                    cnt++;
                    i++;
                }

                for (int j = 3; j <= cnt; j++)
                    ans += cnt - j + 1;
            }
            else
                i++;
        }
        return ans;
    }
};