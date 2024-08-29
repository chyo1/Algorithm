#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int nn, mm, ex, ey, cnt;
int mv[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
string root[4] = {"d", "l", "r", "u"}, ans = "";

bool getPath(int x, int y, string tmp, int cnt) {
    if (cnt == 0) {
        if (x != ex || y != ey)
            return false;
        ans = tmp;
        return true;
    }
    int dis = abs(x - ex) + abs(y - ey);
    for (int i = 0; i < 4; i++) {
        int nx = x + mv[i][0], ny = y + mv[i][1];
        if (nx < 1 || ny < 1 || nn < nx || mm < ny) continue;
        if (cnt < dis || dis % 2 != cnt % 2) continue;
        if (getPath(nx, ny, tmp + root[i], cnt - 1))
            return true;
    }
    return false;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer;
    nn = n, mm = m, ex = r, ey = c, cnt = k;
    
    getPath(x, y, "", k);
    if (ans == "")
        return "impossible";
    return ans;
}