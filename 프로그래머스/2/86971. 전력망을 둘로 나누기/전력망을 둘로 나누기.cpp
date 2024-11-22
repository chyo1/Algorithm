#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_VAL 101

vector<int> tree[MAX_VAL];

// 잘린 상태 중 한 쪽의 송전탑 개수 구하기
int getDividedCount(int v1, int v2, int nodeCnt) {
    bool visited[MAX_VAL] = {false, };
    int cnt = 1;
    
    queue<int> q;
    
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next : tree[now]) {
            if ((now == v1 && next == v2) || (now == v2 && next == v1) || visited[next]) continue;
            visited[next] = true;
            q.push(next);
            cnt++;
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) { 
    int answer = MAX_VAL;
    
    // 트리 정보 만들기
    for (vector<int> wire : wires) {
        tree[wire[0]].push_back(wire[1]);
        tree[wire[1]].push_back(wire[0]);
    }
    
    // 전선 하나씩 끊으면서 송저납 개수 간의 차이 구하기
    for (vector<int> wire : wires) {
        int cnt = getDividedCount(wire[0], wire[1], n);
        answer = min(answer, abs(cnt - (n - cnt)));
    }
    
    return answer;
}
