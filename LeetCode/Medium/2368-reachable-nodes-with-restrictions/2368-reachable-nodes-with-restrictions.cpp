class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> lines[10000];
        bool visited[10000] = {false, };

        int size = edges.size();
        for (int i = 0; i < size; i++) {
            lines[edges[i][0]].push_back(edges[i][1]);
            lines[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i = 0; i < restricted.size(); i++)
            visited[restricted[i]] = true;
        return countReachableNodes(lines, visited, 0);
    }
    int countReachableNodes(vector<int> lines[], bool visited[], int now) {
        int cnt = 1;
        visited[now] = true;
        for(int next:lines[now]) {
            if (!visited[next])
                cnt += countReachableNodes(lines, visited, next);
        }
        return cnt;
    }
    
};