class Solution {
public:
    vector<int> man[100000];

    int dfs(int nowID, vector<int>& manager, vector<int>& informTime) {
        
        if (manager[nowID] != -1) {
            informTime[nowID] += dfs(manager[nowID], manager, informTime);
            manager[nowID] = -1;
        }
        return informTime[nowID];
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int maxTime = 0;
        for (int i = 0; i < n; i++) {
            int superior = manager[i];
            if (superior != -1)
                maxTime = max(maxTime, dfs(superior, manager, informTime));
        }
        
        return maxTime;
    }
};