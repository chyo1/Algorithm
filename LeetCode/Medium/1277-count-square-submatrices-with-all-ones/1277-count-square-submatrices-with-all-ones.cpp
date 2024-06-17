class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>>& dp = matrix;
        int cnt = 0;

        for (int i = 0; i < row; i++) cnt += dp[i][0];
        for (int j = 1; j < col; j++) cnt += dp[0][j];
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (!dp[i][j]) continue;
                dp[i][j] = min(dp[i -1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                cnt += dp[i][j];
            }
        }
        return cnt;
    }
};