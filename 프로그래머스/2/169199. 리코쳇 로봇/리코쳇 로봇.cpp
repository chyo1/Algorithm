#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[100][100];

int solution(vector<string> board) {
    int r = board.size(), c = board[0].size();
    int sx, sy;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'R') {
                sx = i, sy = j;
                break;
            }
        }
    }

    queue<pair<pair<int, int>, int>> q;
    int mv[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    visited[sx][sy] = true;
    q.push({{sx, sy}, 0});
    
    while (!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second, cnt = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x, ny = y;
            while (0 <= nx && nx < r && 0 <= ny && ny < c && board[nx][ny] != 'D')
                nx += mv[i][0], ny += mv[i][1];
            nx -= mv[i][0], ny -= mv[i][1];
            
            if (board[nx][ny] == 'G')
                return cnt + 1;

            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({{nx, ny}, cnt + 1});
        }
    }
    return -1;
}
