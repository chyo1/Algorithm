class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> removal(m, vector<int>(n, 1'000'000));
        removal[0][0] = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 0, 0});

        int mv[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            vector<int> now = q.top();
            int removalCnt = now[0], r = now[1], c = now[2];
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + mv[i][0], nc = c + mv[i][1];
                if (nr < 0 || m <= nr || nc < 0 || n <= nc || removal[nr][nc] <= removalCnt + grid[nr][nc]) continue;
                removal[nr][nc] = removalCnt + grid[nr][nc];
                q.push({removal[nr][nc], nr, nc});
            }
        }
        return removal[m - 1][n - 1];
    }
};