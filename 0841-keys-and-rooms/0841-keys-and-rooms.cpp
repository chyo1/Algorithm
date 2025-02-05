class Solution {
public:
    bool visited[1001] = {false, };
    void dfs(vector<vector<int>>& rooms, int now) {
        if (visited[now]) return;

        visited[now] = true;
        for (int next : rooms[now]) 
            dfs(rooms, next);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(rooms, 0);

        for (int i = 0; i < rooms.size(); i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
};