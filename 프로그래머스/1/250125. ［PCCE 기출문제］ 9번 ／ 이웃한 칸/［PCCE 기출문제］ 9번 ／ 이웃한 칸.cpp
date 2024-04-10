#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size();
    string color = board[h][w];
    int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
    
    for(int i = 0; i < 4; i++) {
        int nx = h + dx[i], ny = w + dy[i];
        
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (board[nx][ny] == color)
            answer++;
    }
    return answer;
}