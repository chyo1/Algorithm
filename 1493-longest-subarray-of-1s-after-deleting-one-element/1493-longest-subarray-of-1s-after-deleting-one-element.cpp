class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int, int>> lens;
        
        int size = nums.size();
        int one = 0, zero = 0;
        bool zeroFlag = !nums[0], flag = false;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 1) {
                if (zeroFlag) {
                    zeroFlag = false;
                    if (zero > 1)
                        lens.push_back({-zero, 0});
                    zero = 0;
                }
                one++;
            }
            else {
                if (!zeroFlag) {
                    zeroFlag = true;
                    lens.push_back({one, 1});
                    one = 0;
                }
                zero++;
                flag = true;
            }
        }
        if (zeroFlag) {
            if (zero > 1)
                lens.push_back({-zero, 0});
        }
        else
            lens.push_back({one, 1});

        int cnt = lens.size();
        if (!flag)
            return lens[0].first - 1;
        int bef = 0, maxLen = 0;

        for (int i = 0; i < cnt; i++) {
            // printf("%d : %d\n", lens[i].second, lens[i].first);

            maxLen = max(maxLen, lens[i].first + bef);
            bef = lens[i].first;
            if (lens[i].second == 0)
                bef = 0;
        }
        return maxLen;
    }
};