class Solution {
    public int solution(int n, int[] tops) {
        int DIV = 10007;
        
        int[] a = new int[n + 1];
        int[] b = new int[n + 1];
        
        a[1] = 1;
        b[1] = tops[0] == 1 ? 3 : 2;
        
        for (int i = 2; i <= n; i++) {
            a[i] = (a[i - 1] + b[i - 1]) % DIV;
            if (tops[i - 1] == 1) 
                b[i] = (2 * a[i - 1] + 3 * b[i - 1]) % DIV;
            else 
                b[i] = (a[i - 1] + 2 * b[i - 1]) % DIV;
        }
        return (a[n] + b[n]) % DIV;
    }
}