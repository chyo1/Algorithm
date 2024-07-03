class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        if (matrix[m - 1][n - 1] < target)
            return false;

        for (int i = 0; i < m; i++) {
            if (target < matrix[i][0])
                return false;
            if (matrix[i][n - 1] < target)
                continue;

            int start = 0, end = n;
            while (start <= end) {
                int mid = (start + end) / 2;

                printf("s %d e %d m %d\n", start, end, mid);
                if (matrix[i][mid] == target)
                    return true;
                else if (matrix[i][mid] < target)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return false;
    }
};