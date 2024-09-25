class Solution {
public:
    vector<int> man[100000];

    int dfs(int nowID, vector<int>& informTime) {
        int maxInformTime = 0;
        for (int subordinate : man[nowID]) {
            maxInformTime = max(dfs(subordinate, informTime), maxInformTime);
        }
        return maxInformTime + informTime[nowID];
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int i = 0; i < n; i++) {
            int superior = manager[i];
            if (superior == -1) continue;
            man[superior].push_back(i);
        }
        
        return dfs(headID, informTime);
    }
};