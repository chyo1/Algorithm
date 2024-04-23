class Solution {
private:
    #define INF 10000

public:
    int openLock(vector<string>& deadends, string target) {
        int time[10000];
        queue <pair<string, int>> q;

        // init
        fill(time, time + 10000, 0);

        // deadends 접근 불가 처리
        for (int i = 0; i < deadends.size(); i++)
            time[stoi(deadends[i])] = INF;
            
        // 시작지점에 접근 불가능 or 시작 지점 = target
        if (time[0] == INF)
            return -1;
        if (target == "0000")
            return 0;

        q.push({"0000", 0});
        while (!q.empty()) {
            string now = q.front().first;
            int cnt = q.front().second;
            q.pop();

            // 8개 케이스 체크
            string next;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 4; j++) {
                    next = now;

                    if (i == 0) { // +
                        if (next[j] == '9') next[j] = '0';
                        else next[j] += 1;
                    }

                    else { // -
                        if (next[j] == '0') next[j] = '9';
                        else next[j] -= 1;
                    }

                    if (next == target)
                        return cnt + 1;

                    // 이전에 해당 수에 접근했다면 -> 최소 횟수가 아니므로 큐에 저장할 필요 없음
                    if (time[stoi(next)] > 0) continue;

                    time[stoi(next)] = cnt + 1;
                    q.push({next, cnt + 1});
                }

            } 
        }
        return -1;
    }
};