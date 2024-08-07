class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> nums;

        for (int i = 0; i < nums1.size(); i++)
            nums.push_back({nums2[i], nums1[i]});

        sort(nums.rbegin(), nums.rend());

        priority_queue <int, vector<int>, greater<int>> pq;
        long long sum = 0, ans = 0;
        for (auto& [n2, n1] : nums) {
            sum += n1;
            pq.emplace(n1);

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                ans = max(ans, sum * n2);
            }
        }
        return ans;
    }
};