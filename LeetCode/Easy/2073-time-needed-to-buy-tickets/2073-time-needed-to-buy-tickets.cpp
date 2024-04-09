class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        deque <pair<int,int>> q;
        int cnt = 0;

        for(int i = 0; i < tickets.size(); i++) {
            q.push_back({tickets[i], i});
        }

        while (!q.empty()) {
            int val = q.front().first, num = q.front().second;

            q.pop_front();

            if (val == 1 && num == k)
                return cnt + 1;
            if (val == 0)
                continue;
            q.push_back({val - 1, num});
            cnt++;
        }
        return cnt + 1;
    }
};