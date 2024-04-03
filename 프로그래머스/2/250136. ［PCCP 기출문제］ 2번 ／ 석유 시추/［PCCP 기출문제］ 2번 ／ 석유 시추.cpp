#include <vector>
#include <algorithm>

using namespace std;

#define MAX_LAND 510
typedef pair<int,int> pp;

bool visited[MAX_LAND][MAX_LAND];
int oils[MAX_LAND];
int N, M, miny, maxy;

// move to left, right, up, down
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

int dfs(vector<vector<int>>&land, int x, int y) {
    int totalOilInField = 1;
    
     // 해당 지점 방문 표시
    visited[x][y] = true;

    // 해당 구역이 걸쳐있는 가로줄 구함
    miny = min(y, miny), maxy = max(y, maxy);
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || N <= nx || ny < 0 || M <= ny || !land[nx][ny] || visited[nx][ny]) continue;
        
        // 현재 구역의 석유 양 계산 
        totalOilInField += dfs(land, nx, ny);
    }

    return totalOilInField;
}

int solution(vector<vector<int>> land) {
    int answer = 0;

    N = land.size(), M = land[0].size();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!land[i][j] || visited[i][j]) continue;
            
            miny = MAX_LAND, maxy = -1;
            
            // 해당 구역의 석유 양 추출 및 해당 구역의 가로 범위 저장
            int amount = dfs(land, i, j);       
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