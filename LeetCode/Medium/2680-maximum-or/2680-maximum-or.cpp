typedef long long ll;
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int size = nums.size();
        vector<ll> pre(size), suf(size);

        pre[0] = nums[0], suf[size - 1] = nums[size - 1];

        for (int i = 1; i < size; i++)
            pre[i] = pre[i - 1] | nums[i];

        for (int i = size - 2; i >= 0; i--)
            suf[i] = suf[i + 1] | nums[i];
        
        pre.insert(pre.begin(), 0);
        suf.insert(suf.begin(), 0);
        nums.insert(nums.begin(), 0);
        pre.push_back(0);
        suf.push_back(0);

        ll ans = -1;
        for (int i = 1; i < size + 1; i++)
            ans = max(ans, pre[i - 1] | suf[i + 1] | ((ll)nums[i] << k));

        return ans;
    }
};