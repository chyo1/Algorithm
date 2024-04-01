typedef long long ll;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        ll minAverage = 100'000'000'000;
        int minIdx = 0;
        int size = nums.size();
        vector <ll> sum(size + 1), cal1(size + 1), cal2(size + 1);

        // 누적합 &  현재까지의 계산값 저장
        sum[1] = cal1[1] = nums[0];
        for (int i = 2; i <= size; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
            cal1[i] = sum[i] / i;
        }

        for (int i = 1; i <= size; i++) {
            ll val;
            if (i == size)
                val =  abs(cal1[i] - (sum[size] - sum[i]));
            else
                val = abs(cal1[i] - (sum[size] - sum[i]) / (size - i));
            // cout << "val : " << val << endl;
            if (val < minAverage) {
                minAverage = val;
                minIdx = i - 1;
            }
        }
        return minIdx;
    }
};
/*

2 3 3 4 4

4 2 0
4 6 6

4 3 2

4 + 1 = 5
3 + 3 = 6
2 + 0 = 2
*/