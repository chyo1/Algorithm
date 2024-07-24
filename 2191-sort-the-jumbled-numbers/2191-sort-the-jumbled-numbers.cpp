class Solution {
public:

    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int numsSize = nums.size();
        vector<pair<int, int>> mapNums(numsSize);

        int mappedNum[10];
        for (int i = 0; i < numsSize; i++) {
            mapNums[i].second = nums[i];
            int len = 0;
            while (nums[i] != 0) {
                mappedNum[len++] = mapping[nums[i] % 10];
                nums[i] /= 10;
            }
            int tmp = 0;
            if (mapNums[i].second == 0)
                mapNums[i].first = mapping[0];
            else {
                for (int j = len - 1; j >= 0; j--)
                    tmp = tmp * 10 + mappedNum[j];
                mapNums[i].first = tmp;
            }
        }
        sort(mapNums.begin(), mapNums.end(), cmp);

        vector<int> ans(numsSize);

        for (int i = 0; i < numsSize; i++)
            ans[i] = mapNums[i].second;
        return ans;
    }
};