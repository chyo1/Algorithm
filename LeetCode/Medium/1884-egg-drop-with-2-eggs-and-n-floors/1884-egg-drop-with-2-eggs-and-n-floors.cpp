class Solution {
#define MAX_VAL 10000 //
public:
    int twoEggDrop(int n) {
        int dp[1001], step = 0;

        while (n > 0) {
            dp[n] = step + 1;
            n -= ++step;
        }
        return step;
    }
};