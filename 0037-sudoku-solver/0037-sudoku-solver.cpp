class Solution {
public:
    bool checkRow[10][10] = {false, }, checkCol[10][10] = {false, }, checkTri[3][3][10] = {false, };
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> emptyCell;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    emptyCell.push_back({i, j});
                else {
                    int num = board[i][j] - '0'; 
                    checkRow[i][num] = checkCol[j][num] = checkTri[i / 3][j / 3][num] = true;
                }
            }
        }

        fillSudoku(board, emptyCell, 0);
    }

    bool fillSudoku(vector<vector<char>>& board, vector<pair<int,int>>& emptyCell, int nowIdx) {
        if (nowIdx == emptyCell.size())
            return true;

        int r = emptyCell[nowIdx].first, c = emptyCell[nowIdx].second;
        for (int i = 1; i <= 9; i++) {
            if (checkRow[r][i] || checkCol[c][i] || checkTri[r / 3][c / 3][i]) continue;
            board[r][c] = i + '0';
            checkRow[r][i] = checkCol[c][i] = checkTri[r / 3][c / 3][i] = true;
            if (fillSudoku(board, emptyCell, nowIdx + 1))
                return true;
            checkRow[r][i] = checkCol[c][i] = checkTri[r / 3][c / 3][i] = false;
        }
        return false;
    }
};