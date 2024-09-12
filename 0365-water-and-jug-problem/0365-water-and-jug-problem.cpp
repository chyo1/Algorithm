class Solution {
public:
    typedef pair<int, int> pp;
    bool visited[2001][2001];
    bool canMeasureWater(int x, int y, int target) {
        return bfs(x, y, target);
    }

    bool bfs(int x, int y, int target) {
        queue<pp> q;

        q.push({0, y});
        q.push({x, 0});
        visited[0][y] = visited[x][0] = true;

        while (!q.empty()) {
            pp now = q.front();
            q.pop();

            // cout << now.first << " " << now.second << endl;

            if (now.first == target || now.second == target || now.first + now.second == target)
                return true;

            // 채우기
            if (!visited[now.first][y]) {
                q.push({now.first, y});
                visited[now.first][y] = true;
            }
            if (!visited[x][now.second]) {
                q.push({x, now.second});
                visited[x][now.second] = true;
            }

            // 버리기
            if (now.first && !visited[now.first][0]) {
                q.push({now.first, 0});
                visited[now.first][0] = true;
            }
            if (now.second && !visited[0][now.second]) {
                q.push({0, now.second});
                visited[0][now.second] = true;
            }

            // 옆으로 넘기기
            if (now.first + now.second > x) {
                if (!visited[x][now.second - (x - now.first)])
                    q.push({x, now.second - (x - now.first)});
            }
            else {
                if (!visited[now.first + now.second][0])
                q.push({now.first + now.second, 0});
            }

            if (now.first + now.second > y) {
                if (!visited[now.first - (y - now.second)][y])
                    q.push({now.first - (y - now.second), y});
            }
            else {
                if (!visited[0][now.first + now.second])
                q.push({0, now.first + now.second});
            }

        }
        return false;
    }
};