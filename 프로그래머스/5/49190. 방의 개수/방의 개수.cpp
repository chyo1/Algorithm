#include <string>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> pi;

int solution(vector<int> arrows) {
    int answer = 0;
    map<pi, bool> visited;
    map<pair<pi, pi>, bool> edgeVisited;
    int mv[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    
    pi now = {0, 0};
    visited[now] = true;

    int size = arrows.size();
    for (int i = 0; i < size; i++) {
        int dir = arrows[i];
        for (int j = 0; j < 2; j++) {
            pi next = {now.first + mv[dir][0], now.second + mv[dir][1]};
            
            if (visited[next] == true && edgeVisited[{now, next}] == false)
                answer++;
            
            visited[next] = true;
            edgeVisited[{now, next}] = true;
            edgeVisited[{next, now}] = true;
            now = next;
            
        }
    }
    return answer;

}