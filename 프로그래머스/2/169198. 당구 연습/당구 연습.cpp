#include <string>
#include <vector>
#include <climits>

typedef long long ll;
using namespace std;

ll dis(ll sx, ll sy, ll x, ll y) {
    ll dx = sx - x;
    ll dy = sy - y;
    return dx * dx + dy * dy;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for (auto ball : balls) {
        int x = ball[0], y = ball[1];
        
        ll minDis = LONG_MAX;
        
        if (!(x == startX && y > startY))
            minDis = min(minDis, dis(startX, startY, x, n + n - y));
        
        if (!(y == startY && x > startX))
            minDis = min(minDis, dis(startX, startY, m + m - x, y));
        
        if (!(x == startX && y < startY))
            minDis = min(minDis, dis(startX, startY, x, -y));
        
        if (!(y == startY && x < startX))
            minDis = min(minDis, dis(startX, startY, -x, y));
    
        answer.push_back(minDis);
    }
    return answer;
}