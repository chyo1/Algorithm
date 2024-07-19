class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool zeroRow[200] = {false, }, zeroCol[200] = {false, };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0)
                    zeroRow[i] = zeroCol[j] = true;
            }
        }

        for (int i = 0; i < m; i++) {
            if (zeroRow[i]) {
                for (int j = 0; j < n; j++)
                    matrix[i][j] = 0;
            }
        }

        for (int j = 0; j < n; j++) {
            if (zeroCol[j]) {
                for (int i = 0; i < m; i++)
                    matrix[i][j] = 0;
            }
        }
    }
};