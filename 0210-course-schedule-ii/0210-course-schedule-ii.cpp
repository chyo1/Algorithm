class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int seq[2000] = {0, };
        vector<int> ans, map[2000];
        fill(seq, seq + numCourses, 0);

        // 순서 넣기
        for (int i = 0; i < prerequisites.size(); i++) {
            int bef = prerequisites[i][1], aft = prerequisites[i][0];
            map[bef].push_back(aft);
            seq[aft]++;
        }

        queue<int> q;

        // 순서가 없는 노드 먼저 넣기
        for (int i = 0; i < numCourses; i++) {
            if (seq[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            
            ans.push_back(now);
            for (int next:map[now]) {
                seq[next]--;
                if (!seq[next]) 
                    q.push(next);
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (seq[i] != 0)
                return {};
        }

        return ans;
    }
};