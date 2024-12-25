#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool visited[20001];
vector<string> answer;

bool dfs(vector<vector<string>>& tickets, string now) {
    answer.push_back(now);
    for (int i = 0; i < tickets.size(); i++) {
        vector<string> t = tickets[i];
        if (t[0] == now && !visited[i]) {
            visited[i] = true;
            
            if (!dfs(tickets, t[1])) {
                visited[i] = false;
                answer.pop_back();
            }
        }
    }
    if (answer.size() != tickets.size() + 1)
        return false;
    return true;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    
    dfs(tickets, "ICN");
    return answer;
}