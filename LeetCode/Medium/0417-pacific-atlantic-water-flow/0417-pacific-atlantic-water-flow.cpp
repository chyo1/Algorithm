class Solution {

private:
    pair<bool,bool> accessable[200][200] = {};
    bool visitedPacific[200][200] = {false, }, visitedAtlantic[200][200] = {false, };
    int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int row, col;

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        row = heights.size(), col = heights[0].size();

        // // pacific 초기화
        // for (int i = 0; i < row; i++) {
        //     visitedPacific[i][0] = true;
        //     visitedAtlantic[i][col - 1] = true;
        // }

        // // atlantic 초기화
        // for (int j = 0; j < col; j++) {
        //     visitedPacific[0][j] = true;
        //     visitedAtlantic[row - 1][j] = true;
        // }

        for (int i = 0; i < row; i++) {
            checkPacific(heights, i, 0);
            checkAtlantic(heights, i, col - 1);
        }

        for (int j = 0; j < col; j++) {
            checkPacific(heights, 0, j);
            checkAtlantic(heights, row - 1, j);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                // 둘 다 접근 가능하면 답에 추가
                if (visitedPacific[i][j] && visitedAtlantic[i][j]) {
                    vector<int> co = {i, j};
                    ans.push_back(co);
                }
            }
        }
        return ans;
    }

    void checkPacific(vector<vector<int>>& heights, int r, int c) {
        visitedPacific[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int nr = r + mv[i][0], nc = c + mv[i][1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || visitedPacific[nr][nc]) continue;
            
            if (heights[r][c] <= heights[nr][nc])
                checkPacific(heights, nr, nc);
        }
        return;
    }

    void checkAtlantic(vector<vector<int>>& heights, int r, int c) {
        visitedAtlantic[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int nr = r + mv[i][0], nc = c + mv[i][1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || visitedAtlantic[nr][nc]) continue;

            if (heights[r][c] <= heights[nr][nc])
                checkAtlantic(heights, nr, nc);
        }
        
        return;
    }
};