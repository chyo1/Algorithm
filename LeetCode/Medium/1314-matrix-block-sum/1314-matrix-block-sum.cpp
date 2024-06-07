class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        int sum[101][101] = {0, };

        sum[0][0] = mat[0][0];
        for (int i = 1; i < m; i++) sum[i][0] = mat[i][0] + sum[i - 1][0];
        for (int j = 1; j < n; j++) sum[0][j] = mat[0][j] + sum[0][j - 1];

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                sum[i][j] = mat[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                printf("%d ", sum[i][j]);
            printf("\n");
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            vector<int> col;
            for (int j = 0; j < n; j++) {
                int val = sum[min(i + k, m - 1)][min(j + k, n - 1)];
                int flag = 0;
                if (i - k - 1 >= 0){
                    val -= sum[i - k - 1][min(j + k, n - 1)];
                    flag++;
                }
                if (j - k - 1 >= 0){
                    val -= sum[min(i + k, m - 1)][j - k - 1];
                    flag++;
                }
                if (flag == 2)
                    val += sum[max(i - k - 1, 0)][max(j - k - 1, 0)];
                col.push_back(val);
            }
            ans.push_back(col);
        }
        return ans;
    }
};

/*
1 2 3
4 5 6
7 8 9

1   3  6
5  12 21
12 27 45

12 21 16
27 45 33
24 39 28
*/