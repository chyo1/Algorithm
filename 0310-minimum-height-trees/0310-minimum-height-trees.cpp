class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 1)
            return {0};

        vector<int> graph[n], ans;
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
                int pairNode = graph[node][0];
                graph[pairNode].erase(find(graph[pairNode].begin(), graph[pairNode].end(), node));
                if (graph[pairNode].size() == 1)
                    nextNodes.push_back(pairNode);
            }
            ans.clear();
            ans = nextNodes;
        }
        return ans;
    }
};