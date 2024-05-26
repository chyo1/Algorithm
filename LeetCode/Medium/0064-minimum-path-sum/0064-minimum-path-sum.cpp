class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        // row[0] 증가
        for (int j = 1; j < n; j++)
            grid[0][j] += grid[0][j - 1];

        for (int i = 1; i < m; i++) {
            // col[0] 증가
            grid[i][0] += grid[i - 1][0];

            for (int j = 1; j < n; j++)
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);

        }
        return grid[m - 1][n - 1];
    }
};