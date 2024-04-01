#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
 
int N, M;
int map[9][9];
int tmp[9][9];
vector<pair<int, int> >vir;
queue<pair<int, int> > q;
int p_x[4] = { 1,0,-1,0 };
int p_y[4] = { 0,1,0,-1 };
int ans;
 
void print() {
    cout << endl;
    for (int Y = 0; Y < N; Y++) {
        for (int X = 0; X < M; X++) {
            cout << tmp[Y][X] << " ";
        }
        cout << endl;
    }
}
 
void cnt_() {
    int cnt1 = 0;
    for (int Y = 0; Y < N; Y++) {
        for (int X = 0; X < M; X++) {
            if (tmp[Y][X] == 0)
                cnt1++;
        }
    }
    ans = max(ans, cnt1);
}
 
void S_V() {
    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + p_x[i];
            int ny = y + p_y[i];
            if (nx > -1 && nx<M&&ny > -1 && ny < N&&tmp[ny][nx] == 0) {
                tmp[ny][nx] = 2;
                q.push(make_pair(ny, nx));
            }
        }
    }
    //print();
    cnt_();
}
 
void make_wall(int cnt) {
    if (cnt == 3) {
        for (int Y = 0; Y < N; Y++) {
            for (int X = 0; X < M; X++) {
                tmp[Y][X] = map[Y][X];
            }
        }
        for (int i = 0; i < vir.size(); i++) {
            int a = vir[i].first;
            int b = vir[i].second;
            q.push(make_pair(a, b));
        }
        S_V();
        //print();
        return;
    }
    for (int Y = 0; Y < N; Y++) {
        for (int X = 0; X < M; X++) {
            if (map[Y][X] == 0) {
                map[Y][X] = 1;
                make_wall(cnt + 1);
                map[Y][X] = 0;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> N >> M;
    ans = 0;
    for (int Y = 0; Y < N; Y++) {
        for (int X = 0; X < M; X++) {
            cin >> map[Y][X];
            if (map[Y][X] == 2)
                vir.push_back(make_pair(Y, X));
        }
    }
    make_wall(0);
    cout << ans;
}