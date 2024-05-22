class Solution {
public:
    int integerReplacement(int n) {
        unordered_set <long long> u;
        queue <pair<long long, int>> q;

        q.push({n, 0});
        u.insert(n);
        while(q.size()) {
            long long num = q.front().first, cnt = q.front().second;
            q.pop();

            if (num == 1)
                return cnt;

            if (num % 2) {
                if (u.find(num + 1) == u.end())
                    q.push({num + 1, cnt + 1});
                if (u.find(num - 1) == u.end())
                    q.push({num - 1, cnt + 1});
            }
            else {
                if (u.find(num / 2) == u.end())
                    q.push({num / 2, cnt + 1});
            }
        }
        return 0;
    }
};