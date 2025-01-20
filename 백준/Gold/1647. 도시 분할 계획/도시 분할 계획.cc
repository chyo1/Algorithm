#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, M;
vector<int> parents;
int lineCount = 0;
int totalCost = 0;

void unionNodes(int a, int b) {
    parents[b] = a;
}

int find(int a) {
    if (a == parents[a]) {
        return a;
    }
    return parents[a] = find(parents[a]);
}

int main() {
    // input
    scanf("%d %d", &N, &M);

    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

    for (int i = 0; i < M; i++) {
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        pq.push({cost, start, end}); // Note: cost first for priority_queue
    }

    // init
    parents.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        parents[i] = i;
    }

    // Kruskal's Algorithm
    while (lineCount < N - 2) {
        vector<int> edge = pq.top();
        pq.pop();
        int cost = edge[0], a = edge[1], b = edge[2];
        int p1 = find(a), p2 = find(b);

        if (p1 != p2) {
            unionNodes(p1, p2);
            totalCost += cost;
            lineCount++;
        }
    }

    // output
    printf("%d\n", totalCost);

    return 0;
}
