class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int size = grid.size();
        int cnt = 0;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int idx = 0;

                while (idx < size && grid[i][idx] == grid[idx][j])
                    idx++;
                    
                if (idx == size)
                    cnt++;
            }
        }
        return cnt;
    }
};