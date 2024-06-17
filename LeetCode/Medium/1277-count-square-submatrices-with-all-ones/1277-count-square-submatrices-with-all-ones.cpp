class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int sum = 0;
        int row = matrix.size(), col = matrix[0].size();
        int maxSubmatrixSize = min(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 1; k <= maxSubmatrixSize; k++) {
                    if (!matrix[i][j] || row < i + k || col < j + k || !checkSize(i, j, k, matrix))
                        break;
                    // printf("i: %d, j: %d, size: %d\n", i, j, k);
                    sum++;
                }
            }
        }
        return sum;
    }

    bool checkSize(int r, int c, int size, vector<vector<int>>& matrix) {
        int row = r + size, col = c + size;
        for (int i = r; i < row; i++) {
            for (int j = c; j < col; j++) {
                if (matrix[i][j] == 0)
                    return false;
            }
        }
        return true;
    }
};