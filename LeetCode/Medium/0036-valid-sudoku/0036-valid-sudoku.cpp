class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool checkRow[10], checkCol[10];
        bool checkBox[3][3][10] = {false, };

        for (int i = 0; i < 9; i++) {
            fill(checkRow, checkRow + 10, false);
            fill(checkCol, checkCol + 10, false);
            
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int numRow = board[i][j] - '0';
                    if (checkRow[numRow])
                        return false;
                    checkRow[numRow] = true;

                    if (i <= j && checkBox[i / 3][j / 3][numRow]) {
                        // printf("r: %d c: %d numR: %d\n", i, j, numRow);
                        return false;
                    }
                    checkBox[i / 3][j / 3][numRow] = true;
                }

                if (board[j][i] != '.') {
                    int numCol = board[j][i] - '0';
                    if (checkCol[numCol])
                        return false;
                    checkCol[numCol] = true;

                    if (i == j)
                        continue;
                    if (i <= j && checkBox[j / 3][i / 3][numCol]) {
                        // printf("r: %d c: %d numC: %d\n", j, i, numCol);
                        return false;
                    }
                    checkBox[j / 3][i / 3][numCol] = true;
                }
            }
        }
        return true;
    }
};