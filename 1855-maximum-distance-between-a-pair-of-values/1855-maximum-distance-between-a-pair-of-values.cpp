class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int idx1 = min(nums1.size() - 1, nums2.size() - 1), idx2 = nums2.size() - 1;
        int maxLen = 0;

        for (; idx2 >= 0; idx2--) {
            while (0 <= idx1 && nums1[idx1] <= nums2[idx2])
                idx1--;
            if (idx1 != nums1.size() - 1)
                idx1++;
            if (nums1[idx1] <= nums2[idx2])
                maxLen = max(maxLen, idx2 - idx1);
        }
        return maxLen;
    }
};