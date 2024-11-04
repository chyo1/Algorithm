#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int getDifferentCnt(string base, string target) {
    int cnt = 0;
    for (int i = 0; i < base.size(); i++) 
        cnt += base[i] != target[i];
    return cnt;
}

int solution(string begin, string target, vector<string> words) {
    
    // target이 words에 없음
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;
    
    unordered_map<string, int> visited;
    queue<pair<string, int>> q;
    
    // bfs
    q.push({begin, 0});
    while (!q.empty()) {
        auto [str, cnt] = q.front();
        q.pop();
        
        for (string word : words) {
            
            // 1자리만 다르지 않음 || 이미 확인한 단어
            if (getDifferentCnt(str, word) != 1 || visited.find(word) != visited.end()) continue;
            
            // 답
            if (word == target)
                return cnt + 1;
            
            // 방문 처리 후 큐에 삽입
            visited[word] = 1;
            q.push({word, cnt + 1});
        }
    }
    return 0;
}