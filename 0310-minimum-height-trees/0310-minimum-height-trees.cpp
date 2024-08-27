class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 1)
            return {0};

        // graph를 list로 정의
        list<int> graph[n];
        vector<int> ans;

        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1)
                ans.push_back(i);
        }

        while (n > 2) {
            n -= ans.size();

            vector<int> nextNodes;
            for (auto node : ans) {
                int pairNode = graph[node].front();  // 첫 번째 원소 가져옴
                graph[pairNode].remove(node);  // 연결 리스트에서 값 삭제
                if (graph[pairNode].size() == 1)
                    nextNodes.push_back(pairNode);
            }
            ans.clear();
            ans = nextNodes;
        }
        return ans;
    }
};
