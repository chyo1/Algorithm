class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            vector<int> col;
            for (int j = 0; j < n; j++) {
                col.push_back(getAnswer(i, j, k, m, n, mat));
            }
            ans.push_back(col);
        }
        return ans;
    }

    int getAnswer(int i, int j, int k, int m, int n, vector<vector<int>>& mat) {
        int sum = 0;
        for (int r = max(i - k, 0); r <= min(i + k, m - 1); r++) {
            for (int c = max(j - k, 0); c <= min(j + k, n - 1); c++) {
                sum += mat[r][c];
            }
        }
        return sum;
    }

};
/*
1 2 3
4 5 6
7 8 9

12 21 16
27 45 33
24 39 28
*/