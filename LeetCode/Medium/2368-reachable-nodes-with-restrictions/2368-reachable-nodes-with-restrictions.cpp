class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> lines[100000];
        bool visited[100000] = {false, };

        // restricted 배열 정보 저장
        for (int i = 0; i < restricted.size(); i++)
            visited[restricted[i]] = true;

        // 간선 정보 저장
        int size = edges.size();
        for (int i = 0; i < size; i++) {
            int start = edges[i][0], end = edges[i][1];
            if (visited[start] || visited[end])
                continue ;
            lines[start].push_back(end);
            lines[end].push_back(start);
        }

        return countReachableNodes(lines, visited, 0);
    }

    int countReachableNodes(vector<int> (&lines)[100000], bool (&visited)[100000], int now) {
        int cnt = 1;
        visited[now] = true;

        // 방문하지 않은 노드라면 방문
        for(int next:lines[now]) {
            if (!visited[next])
                cnt += countReachableNodes(lines, visited, next);
        }
        return cnt;
    }
    
};