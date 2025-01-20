#define A 1
#define B 2

class Solution {
public:
    int group[101];
    bool bfs(vector<vector<int>>& graph, int now) {
        queue<int> q;
        q.push(now);
        group[now] = A;

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            for (int next : graph[now]) {
                if (group[now] == group[next]) return false;
                if (group[next] > 0) continue;
                group[next] = group[now] == A ? B : A;
                q.push(next);
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        for (int i = 0; i <= 100; i++) 
            group[i] = -1;
        
        for (int i = 0; i < graph.size(); i++) {
            if (group[i] > 0) continue;
            if (!bfs(graph, i)) return false;
        }
        return true;
    }
};