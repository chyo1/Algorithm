class Solution {
    public int solution(int n, long l, long r) {
        int answer = 0;
        for (long i = l - 1; i < r; i++) {
            if (isOne(i)) answer++;
        }
        return answer;
    }
    
    private boolean isOne(long n) {
        while (5 <= n) {
            if ((n - 2) % 5 == 0)
                return false;
            n /= 5;
        }
        return n != 2;
    }
}