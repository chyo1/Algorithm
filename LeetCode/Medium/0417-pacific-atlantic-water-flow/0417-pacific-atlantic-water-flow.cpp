class Solution {

private:
        pair<bool,bool> accessable[200][200] = {};
        bool visited[200][200] = {false, };
        int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int row, col;

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        row = heights.size(), col = heights[0].size();

        // pacific 초기화
        for (int i = 0; i < row; i++) {
            accessable[i][0].first = true;
            accessable[i][col - 1].second = true;
        }

        // atlantic 초기화
        for (int j = 0; j < col; j++) {
            accessable[0][j].first = true;
            accessable[row - 1][j].second = true;
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                // 해당 칸에서 둘 다 접근 가능한 지 확인
                fill(visited[0], visited[row], false);
                if (checkPacific(heights, i, j))
                    accessable[i][j].first = true;

                fill(visited[0], visited[row], false);
                if (checkAtlantic(heights, i, j))
                    accessable[i][j].second = true;
                

                // 둘 다 접근 가능하면 답에 추가
                if (accessable[i][j].first && accessable[i][j].second) {
                    vector<int> co = {i, j};
                    ans.push_back(co);
                }
            }
        }
        return ans;
    }

    bool checkPacific(vector<vector<int>>& heights, int r, int c) {
        if (accessable[r][c].first)
            return true;
        visited[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int nr = r + mv[i][0], nc = c + mv[i][1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || visited[nr][nc]) continue;

            if (heights[r][c] >= heights[nr][nc]) {
                if (checkPacific(heights, nr, nc)) {
                    accessable[r][c].first = true;
                    return true;
                }
            }
        }
        return false;
    }

    bool checkAtlantic(vector<vector<int>>& heights, int r, int c) {
        if (accessable[r][c].second)
            return true;
        visited[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int nr = r + mv[i][0], nc = c + mv[i][1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || visited[nr][nc]) continue;

            if (heights[r][c] >= heights[nr][nc]) {
                if (checkAtlantic(heights, nr, nc)) {
                    accessable[r][c].second = true;
                    return true;
                }
            }
        }
        return false;
    }
};