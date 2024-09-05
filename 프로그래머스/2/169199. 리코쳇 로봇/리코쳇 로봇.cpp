#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[100][100];
int r, c, sx, sy, ex, ey, ans = 1000000000;
int mv[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool dfs(vector<string>& board, int x, int y, int cnt) {
    for (int i = 0; i < 4; i++) {
        int nx = x, ny = y;
        while (0 <= nx && nx < r && 0 <= ny && ny < c && board[nx][ny] != 'D') {
            nx += mv[i][0], ny += mv[i][1];
        }
        nx -= mv[i][0], ny -= mv[i][1];
        if (board[nx][ny] == 'G') {
            ans = min(cnt, ans);
            return false;
        }
        if (visited[nx][ny]) continue;
        visited[nx][ny] = true;
        if (dfs(board, nx, ny, cnt + 1))
            return true;
    }
    return false;
}

int solution(vector<string> board) {
    r = board.size(), c = board[0].size();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'R') {
                sx = i, sy = j;
                break;
            }
        }
    }
    visited[sx][sy] = true;
    queue<pair<pair<int, int>, int>> q;
    
    q.push({{sx, sy}, 0});
    while (!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second, cnt = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x, ny = y;
            while (0 <= nx && nx < r && 0 <= ny && ny < c && board[nx][ny] != 'D') {
                nx += mv[i][0], ny += mv[i][1];
            }
            nx -= mv[i][0], ny -= mv[i][1];
            
            if (board[nx][ny] == 'G')
                return cnt + 1;

            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({{nx, ny}, cnt + 1});
        }
    }
    return -1;
    // dfs(board, sx, sy, 0);
    return ans == 1000000000 ? -1 : ans;
}