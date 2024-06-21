class Solution {
public:
    #define MAX_VAL 100'000
    int parent[MAX_VAL];

    void setUnion(int a, int b) {
        parent[b] = a;
    }

    int find(int now) {
        // printf("now: %d parent[now]: %d\n", now, parent[now]);
        if (parent[now] == now || parent[now] == MAX_VAL)
            return now;
        return parent[now] = find(parent[now]);
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {

        // 집합 관계 자기 자신으로 초기화
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        for (int i = 0; i < restricted.size(); i++)
            parent[restricted[i]] = MAX_VAL;

        int size = edges.size();
        for (int i = 0; i < size; i++) {
            int start = edges[i][0], end = edges[i][1];
            if (parent[start] == MAX_VAL || parent[end] == MAX_VAL) continue;
            int parentA = find(start), parentB = find(end);
            // printf("A: %d, B: %d\n", parentA, parentB);
            setUnion(parentA, parentB);
        }


        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == parent[0]) cnt++;
            // printf("%d %d\n", i, parent[i]);
        }
        return cnt;
    }
    
};