class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int size = grid.size();
        int cnt = 0;
        map<vector<int>, int> m;

        for (int i = 0; i < size; i++)
            m[grid[i]]++;
        
        for (int i = 0; i < size; i++) {
            vector<int> col(size);
            for (int j = 0; j < size; j++)
                col[j] = grid[j][i];
            if (m.count(col))
                cnt += m[col];
        }

        return cnt;
    }
};