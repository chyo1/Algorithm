#include <string>
#include <vector>

using namespace std;

bool visited[10];
int maxCnt = -1;

void dfs(vector<vector<int>>& dungeon, int k, int cnt) {
    for (int i = 0; i < dungeon.size(); i++) {
        auto d = dungeon[i];
        if (visited[i] || k < d[0]) continue;
        
        visited[i] = true;
        dfs(dungeon, k - d[1], cnt + 1);
        visited[i] = false;
    }
    maxCnt = max(maxCnt, cnt);
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(dungeons, k, 0);
    return maxCnt;
}