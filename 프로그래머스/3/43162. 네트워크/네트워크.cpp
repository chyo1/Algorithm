#include <string>
#include <vector>

using namespace std;

bool visited[200] = {false, };
void dfs(vector<vector<int>>& computers, int n, int now) {
    visited[now] = true;
    for (int i = 0; i < n; i++) {
        if (computers[now][i] && !visited[i])
            dfs(computers, n, i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        dfs(computers, n, i);
        answer++;
    }
    return answer;
}