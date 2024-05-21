class Solution {
private:
    #define MAX_SIZE 410
    typedef pair<int, int> pair_int;
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int size = board.size();
        int dst = size * size;
        queue <pair_int> q;
 
        // 배열 인덱싱
        int r, c, idx = 0;
        r = size - 1, c = 0;
        pair_int moveDir = {0, 1};

        while (idx++ != dst) {

            // 사다리 or 뱀 -> 출발 & 도착 지점 저장
            if (board[r][c] != -1)
                q.push({idx, board[r][c]});
            
            c += moveDir.second; 
            if (c == size || c == -1) {
                moveDir.second *= -1;
                r -= 1;
                c += moveDir.second;
            }
        }


        // 모든 인덱스의 도착 지점을 자기 자신으로 설정
        int point[MAX_SIZE];
        for (int i = 0; i < MAX_SIZE; i++)
            point[i] = i;

        // 큐를 순회하며 출발 != 도착인 지점 처리
        while (q.size()) {
            pair_int moveTo = q.front();
            q.pop();
            point[moveTo.first] = moveTo.second;
        }


        // 방문 초기화
        int visited[MAX_SIZE];
        fill(visited, visited + MAX_SIZE, MAX_SIZE);

        queue <int> log;

        // 시작지점
        log.push(1);
        visited[1] = 0;

        // BFS
        while (log.size()) {
            int now = log.front();
            log.pop();
            
            int nextCnt = visited[now] + 1;

            for (int i = 1; i <= 6; i++) {
                int next = now + i;

                // 현재 도달 회수 < 저장된 도달 회수인 경우에 작은 값으로 갱신
                if (next <= dst && visited[point[next]] > nextCnt) {
                    visited[point[next]] = nextCnt;
                    log.push(point[next]);
                }
            }
        }

        // 도착 불가 시 -1 반환
        return visited[dst] != MAX_SIZE ? visited[dst] : -1;
    }
};