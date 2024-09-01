#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 2000000000;
int board[10][2] = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};

string num;
int dp[100001][4][4][4][4];

int findAns(int lx, int ly, int rx, int ry, int idx, int weight) {
    // 값이 큼 || 두 손가락이 같은 위치에 있음
    if (lx == rx && ly == ry)
        return 9999999;
    if (num.size() == idx) {
        ans = weight;
        return dp[idx][lx][ly][rx][ry];
    }
    
    if (dp[idx][lx][ly][rx][ry])
        return dp[idx][lx][ly][rx][ry];
    
    int targetX = board[num[idx] - '0'][0], targetY = board[num[idx] - '0'][1];
    int dx, dy, plus;
    
    // left
    dx = abs(lx - targetX), dy = abs(ly - targetY);
    if (dx == 0 && dy == 0)
        plus = 1;
    else {
        int dia = min(dx, dy), mx = dx - dia, my = dy - dia;
        plus = (dia * 3) + (mx + my) * 2;
    }
    int l = plus + findAns(targetX, targetY, rx, ry, idx + 1, weight + plus);
    
    // right
    dx = abs(rx - targetX), dy = abs(ry - targetY);
    if (dx == 0 && dy == 0)
        plus = 1;
    else {
        int dia = min(dx, dy), mx = dx - dia, my = dy - dia;
        plus = (dia * 3) + (mx + my) * 2;
    }
    int r = plus + findAns(lx, ly, targetX, targetY, idx + 1, weight + plus);
    
    return dp[idx][lx][ly][rx][ry] = min(l, r);
}

int solution(string numbers) {
    num = numbers;
    return findAns(1, 0, 1, 2, 0, 0);
}