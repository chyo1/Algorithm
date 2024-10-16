class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        int third = INT_MIN;

        stack<int> s;
        for (int i = size - 1; i >= 0; i--) {
            if (nums[i] < third)
                return true;
            while (!s.empty() && s.top() < nums[i]) {
                third = s.top();
                s.pop();
            }  
            s.push(nums[i]);
        }
        
        return false;
    }
};
