class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int cnt = 0;

        for (int i = 0; i < row; i++) cnt += matrix[i][0];
        for (int j = 1; j < col; j++) cnt += matrix[0][j];
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (!matrix[i][j]) continue;
                matrix[i][j] = min(matrix[i -1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1])) + 1;
                cnt += matrix[i][j];
            }
        }
        return cnt;
    }
};