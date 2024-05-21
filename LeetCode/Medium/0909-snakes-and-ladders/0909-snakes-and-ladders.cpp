class Solution {
private:
    #define MAX_SIZE 410
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int len = board.size();
        int dst = len * len;
        queue <pair<int, int>> q;
 
        // indexing
        int r, c;
        r = len - 1, c = 0;
        int idx = 0;
        pair<int, int> moveDir = {0, 1};
        while (idx++ != dst) {
            if (board[r][c] != -1) {
                q.push({idx, board[r][c]});
                // printf("%d ", idx);
            }
            c += moveDir.second; 
            if (c == len || c == -1) {
                moveDir.second *= -1;
                r -= 1;
                c += moveDir.second;
            }
        }

        int point[MAX_SIZE];
        for (int i = 0; i < MAX_SIZE; i++)
            point[i] = i;

        // check ladder or snake and change the point's definition
        while (q.size()) {
            pair<int, int> moveTo = q.front();
            q.pop();
            point[moveTo.first] = moveTo.second;
        }
        // for (int i = 0; i <= len * len; i++)
        //     printf("idx: %d, dst: %d\n", i, point[i]);


        int visited[MAX_SIZE];
        fill(visited, visited + MAX_SIZE, MAX_SIZE);

        idx = 1;
        queue <int> log;
        log.push(1); // start point
        visited[1] = 0;
        while (log.size()) {
            int now = log.front();
            log.pop();
            
            int nextCnt = visited[now] + 1;

            for (int i = 1; i <= 6; i++) {
                int next = now + i;
                // printf("next: %d, visited[next] : %d, nextCnt: %d\n", next, visited[next], nextCnt);
                if (next <= dst && visited[point[next]] > nextCnt) {
                    visited[point[next]] = nextCnt;
                    log.push(point[next]);
                    // if (point[next] != next)
                    //     printf("next : %d, step : %d\n", next, nextCnt);
                    // printf("point[next] : %d, step : %d\n", point[next], nextCnt);
                }
            }
        }
        // for (int i = 0; i <= len * len; i++)
        //     printf("idx: %d, dst: %d\n", i, visited[i]);
        
        return visited[dst] != MAX_SIZE ? visited[dst] : -1;
    }
};