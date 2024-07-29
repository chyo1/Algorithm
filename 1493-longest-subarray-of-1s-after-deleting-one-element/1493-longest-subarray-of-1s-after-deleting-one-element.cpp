class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int, int>> lens;
        
        int size = nums.size();
        int one = 0, zero = 0;
        bool flag = !nums[0], zeroCnt = false;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 1) {
                if (flag) {
                    flag = false;
                    if (zero > 1)
                        lens.push_back({-zero, 0});
                    zero = 0;
                }
                one++;
            }
            else {
                if (!flag) {
                    flag = true;
                    lens.push_back({one, 1});
                    one = 0;
                }
                zero++;
                zeroCnt = true;
            }
        }
        if (flag && zero > 1) 
            lens.push_back({-zero, 0});
        if (!flag)
            lens.push_back({one, 1});

        int cnt = lens.size();
        if (!zeroCnt)
            return lens[0].first - 1;
        int bef = 0, maxLen = 0;

        for (int i = 0; i < cnt; i++) {
            maxLen = max(maxLen, lens[i].first + bef);
            bef = lens[i].second ? lens[i].first : 0;
        }
        return maxLen;
    }
};