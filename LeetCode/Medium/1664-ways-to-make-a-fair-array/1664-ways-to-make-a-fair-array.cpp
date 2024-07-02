class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int sum[100002], cnt = 0;
        int oddSum = 0, evenSum = 0, size = nums.size();

        if (size == 1)
            return 1;
        sum[0] = evenSum = nums[0], sum[1] = oddSum = nums[1];
        for (int i = 2; i < size; i++) {
            sum[i] = sum[i - 2] + nums[i];
            if (i % 2 == 0)
                evenSum += nums[i];
            else
                oddSum += nums[i];
        }

        int odd, even;
        for (int i = 0; i < size; i++) {

            if (i == 0) {
                if (evenSum - nums[i] == oddSum)
                    cnt++;
            }

            // 홀수 합
            else if (i % 2) {
                odd = evenSum - sum[i - 1];
                if (i != 1)
                    odd += sum[i - 2];

                even = sum[i - 1] + (oddSum - sum[i]);
            }

            // 짝수 합
            else {
                even = oddSum - sum[i - 1];
                if (i != 0)
                    even += sum[i - 2];

                odd = sum[i - 1] + (evenSum - sum[i]);
            }

            if (odd == even)
                cnt++;
        }
        return cnt;
    }
};