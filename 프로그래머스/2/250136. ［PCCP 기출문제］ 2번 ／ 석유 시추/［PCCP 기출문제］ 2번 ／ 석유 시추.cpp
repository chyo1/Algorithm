#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_LAND 510
typedef pair<int,int> pp;


bool visited[MAX_LAND][MAX_LAND];
int oils[MAX_LAND];
int N, M, miny, maxy;
queue <pp> Q;

// move to left, right, up, down
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

int bfs(vector<vector<int>>& land, int x, int y) {
    int total = 0;

    Q.push({x, y});
    visited[x][y] = true;
    
    while (!Q.empty()) {
        x = Q.front().first, y = Q.front().second;
        Q.pop();
        
       // 해당 구역이 걸쳐있는 가로줄 구함
        miny = min(y, miny), maxy = max(y, maxy);
        
        // 석유 양 저장
        total++;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || N <= nx || ny < 0 || M <= ny || !land[nx][ny] || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
    return total;
}

int solution(vector<vector<int>> land) {
    int answer = 0;

    N = land.size(), M = land[0].size();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!land[i][j] || visited[i][j]) continue;
            
            miny = MAX_LAND, maxy = -1;
            
            // 해당 구역의 석유 양 추출 및 해당 구역의 가로 범위 저장
            int amount = bfs(land, i, j);       
            oils[miny] += amount, oils[maxy + 1] -= amount;
        }
    }
    
    int oilsInLine = 0;
    for (int i = 0; i < M; i++) {
        oilsInLine += oils[i];
        answer = max(answer, oilsInLine);
    }
        
    return answer;
}