class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int row[10][10], col[10][10], left[10][10], right[10][10];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 1) {
                    row[i][j] = grid[i][j - 2] + grid[i][j - 1] + grid[i][j];
                    if (i > 1)
                        right[i][j] = grid[i - 2][j - 2] + grid[i - 1][j - 1] + grid[i][j];// 
                }
                if (i > 1) {
                    col[i][j] = grid[i - 2][j] + grid[i - 1][j] + grid[i][j];
                    if (j < n - 2)
                        left[i][j] = grid[i][j] + grid[i - 1][j + 1] + grid[i - 2][j + 2]; // /
                }
            }
        }

        int cnt = 0;
        for (int i = 2; i < n; i++) {
            for (int j = 2; j < n; j++) {
                int val = row[i][j];
                cout << val << " " << row[i - 2][j] << " " << row[i - 1][j] << endl;
                cout << col[i][j - 2] << " " << col[i][j - 2] << " " << col[i][j] << endl;
                cout << right[i][j] << " " << left[i][j - 2];
                if (!CheckAllUnderTenAndUnique(grid, i - 2, j - 2)
                    || val != row[i - 2][j] || val != row[i - 1][j]
                    || val != col[i][j - 2] || val != col[i][j - 1] || val != col[i][j]
                    || val != right[i][j] || val != left[i][j - 2])
                    continue;
                cnt++;
            }
        }
        return cnt;
    }

    bool CheckAllUnderTenAndUnique(vector<vector<int>>& grid, int r, int c) {
        bool nums[10] = {false, };
        for (int i = r; i < r + 2; i++) {
            for (int j = c; j < c + 2; j++) {
                if (grid[i][j] < 1 || grid[i][j] >= 10 || nums[grid[i][j]] == true)
                    return false;
                nums[grid[i][j]] = true;
            }
        }
        return true;
    }
};