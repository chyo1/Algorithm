class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1)
            return 1;

        priority_queue<int, vector<int>, greater<int>> q;

        q.push(1);

        int now;
        while (n--) {
            now = q.top();
            q.pop();
            while (q.size() && now == q.top())
                q.pop();
            
            for (int prime : primes) {
                if ((long long) now * prime > INT_MAX) break;
                int next = now * prime;
                q.push(next);
            }
        }
        return now;
    }
};