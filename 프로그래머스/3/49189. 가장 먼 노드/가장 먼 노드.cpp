#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<int> graph[20001];
    
    // connect nodes
    for (auto e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    int maxLev = 0, maxLevCnt = 1;
    bool visited[20001];
    queue<pair<int, int>> q;
    
    q.push({1, 1});
    visited[1] = true;
    while (!q.empty()) {
        int now = q.front().first, nowLev = q.front().second;
        q.pop();
        
        // update maxLev Info
        if (nowLev > maxLev) {
            maxLev = nowLev;
            maxLevCnt = 1;
        }
        
        else if (nowLev == maxLev)
            maxLevCnt++;
            
        for (int next : graph[now]) {
            if (visited[next]) continue;
            
            q.push({next, nowLev + 1});
            visited[next] = true;
        }
    }
    return maxLevCnt;
}