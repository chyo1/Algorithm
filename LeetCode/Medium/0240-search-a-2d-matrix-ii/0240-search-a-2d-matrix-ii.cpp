class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n - 1;
        
        // target > matrix의 최댓값
        if (matrix[m - 1][n - 1] < target)
            return false;

        while (row < m && 0 <= col) {
            if (matrix[row][col] == target)
                return true;
            if (matrix[row][col] < target)
                row++;
            else
                col--;
        }
        return false;
    }
};