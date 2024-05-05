class Solution {
private:
    #define MAX_SIZE 50

public:
    int countMines(vector<vector<char>>& board, int r, int c, int row, int col) {
        
        int cnt = 0;
        for (int i = max(r - 1, 0); i < min(r + 2, row); i++) {
            for (int j = max(c - 1, 0); j < min(c + 2, col); j++) {
                if (i == r && j == c)
                    continue;
                
                // 지뢰 주변의 셀이 M -> 지뢰 개수 + 1
                if (board[i][j] == 'M')
                    cnt++;
            }
        }
        return cnt;
    }

    void updateRevealedBoard(vector<vector<char>>& board, int cr, int cc) {
        queue <pair<int, int>> q;
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col));
        
        int mv[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        // 클릭한 셀의 위치부터 시작
        q.push({cr, cc});
        visited[cr][cc] = true;

        while (q.size()) {
            int r = q.front().first, c = q.front().second;
            q.pop();


            if (board[r][c] != 'M' && board[r][c] != 'B') {
                
                // 주어진 셀에 인접한 지뢰 존재 O -> 숫자로 변환
                if ('1' <= board[r][c] && board[r][c] <= '8')
                    continue;
                
                int mineInfo = countMines(board, r, c, row, col);
                if (mineInfo) {
                    board[r][c] = mineInfo + '0';
                    continue;
                }

                // 주어진 셀에 인접한 지뢰 존재 X -> 주변 셀 탐색하며 변환
                board[r][c] = 'B';

                for (int i = 0; i < 8; i++) {
                    int nr = r + mv[i][0], nc = c + mv[i][1];

                    if (nr < 0 || nc < 0 || row <= nr || col <= nc || visited[nr][nc])
                        continue;
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int cr = click[0], cc = click[1];

        // 지뢰 클릭 -> 해당 지뢰만 X로 바꾼 후 반환
        if (board[cr][cc] == 'M') {
            board[cr][cc] = 'X';
            return board;
        }

        updateRevealedBoard(board, cr, cc);

        return board;
    }
};