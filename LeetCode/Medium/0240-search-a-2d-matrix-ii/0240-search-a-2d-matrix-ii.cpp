class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int row = 0, col = 0;
        
        int start = 0, end = m;
        while (start < end) {
            int mid = (start + end) / 2;

            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                start = mid;
            else
                end = mid;

        }
        col = mid;

         while (start < end) {
            int mid = (start + end) / 2;

            if (matrix[mid][col] < target)
                start = mid;
            else
                end = mid;

        }
        row = mid;

        return false;
    }
};