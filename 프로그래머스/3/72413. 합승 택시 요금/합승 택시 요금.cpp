#include <string>
#include <vector>
#include <climits>

using namespace std;
#define INF INT_MAX
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF; 
    
    // 지도 초기화
    int path[201][201] = {0, };
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (i == j) continue;
            path[i][j] = INF;
        }
    }

    for (int i = 0; i < fares.size(); i++) {
        int start = fares[i][0];
        int end = fares[i][1];
        int weight = fares[i][2];

        path[start][end] = path[end][start] = weight;
    }

    // 모든 노선 간의 거리 확인
    for (int k = 1; k < n + 1; k++) {
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (path[i][k] != INF && path[k][j] != INF)
                    path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
            }
        }
    }

    // 헤어지는 노드를 바꿔가며 최소값 찾기
    for (int i = 1; i < n + 1; i++) {
        if (path[s][i] != INF && path[i][a] != INF && path[i][b] != INF)
            answer = min(answer, path[s][i] + path[i][a] + path[i][b]);
    }
    return answer;
}