class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        pair<int, int> loc[m * n + 1];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                loc[mat[i][j]] = {i, j};
            }
        }
        
        int row[100001] = {0, }, col[100001] = {0, };
        int size = arr.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> cor = loc[arr[i]];

            row[cor.first]++, col[cor.second]++;
            if (row[cor.first] == n || col[cor.second] == m)
                return i;
        }
        return size - 1;
    }
};