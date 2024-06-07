class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            vector<int> col;
            for (int j = 0; j < n; j++) {
                col.push_back(getAnswer(max(0, i - k), min(i + k, m - 1), max(j - k, 0), min(j + k, n - 1), mat));
            }
            ans.push_back(col);
        }
        return ans;
    }

    int getAnswer(int r1, int r2, int c1, int c2, vector<vector<int>>& mat) {
        int sum = 0;
        for (int r = r1; r <= r2; r++) {
            for (int c = c1; c <= c2; c++) {
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