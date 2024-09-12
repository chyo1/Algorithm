class Solution {
public:
    bool visited[2001];
    bool canMeasureWater(int x, int y, int target) {
        return bfs(x, y, target);
    }

    bool bfs(int x, int y, int target) {
        queue<int> q;
        int waters[4] = {x, y, -x, -y}, totalWater = x + y;

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            if (now == target)
                return true;
            for (int w : waters) {
                if (0 <= now + w && now + w <= totalWater && !visited[now + w]) {
                    q.push(now + w);
                    visited[now + w] = true;
                }
            }

        }
        return false;
    }
};