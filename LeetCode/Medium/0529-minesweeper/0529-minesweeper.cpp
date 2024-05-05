class Solution {
private:
    #define MAX_SIZE 50

public:
      void fillMineInfo(vector<vector<int>>& info, vector<vector<char>>& board) {
        int row = info.size(), col = info[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                
                // 현재 셀이 지뢰 -> 주변 셀의 지뢰 개수 업데이트
                if (board[i][j] == 'M')
                    checkMineInfo(info, board, i, j, row, col);

                // 주어진 셀이 밝혀진 숫자 -> 주어진 지뢰 개수 저장
                else if ('1' <= board[i][j] && board[i][j] <= '8')
                    info[i][j] = board[i][j] - '0';
            }
        }
    }
    
    void checkMineInfo(vector<vector<int>>& info, vector<vector<char>>& board, int r, int c, int row, int col) {
        for (int i = max(r - 1, 0); i < min(r + 2, row); i++) {
            for (int j = max(c - 1, 0); j < min(c + 2, col); j++) {
                if (i == r && j == c)
                    continue;
                
                // 지뢰 주변의 셀이 E -> 지뢰 개수 + 1
                if (board[i][j] == 'E')
                    info[i][j]++;
            }
        }
    }


    void updateRevealedBoard(vector<vector<int>>& info, vector<vector<char>>& board, int cr, int cc) {
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

            // 주어진 셀에 인접한 지뢰 존재 O -> 숫자로 변환
            if (board[r][c] != 'B' && board[r][c] != 'M' && info[r][c])
                board[r][c] = info[r][c] + '0';

            // 주어진 셀에 인접한 지뢰 존재 X -> 주변 셀 탐색하며 변환
            else if (board[r][c] != 'M'){
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

        int row = board.size(), col = board[0].size();

        vector<vector<int>> mineInfo(row, vector<int>(col));
        
        // 각 셀당 인접한 지뢰 정보를 찾고 저장
        fillMineInfo(mineInfo, board);

        updateRevealedBoard(mineInfo, board, cr, cc);

        return board;
    }
};