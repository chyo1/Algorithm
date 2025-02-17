class Solution {
    public int minInsertions(String s) {
        int open = 0, close = 0, cnt = 0;

        int i = 0;
        while (i < s.length()) {
            if (s.charAt(i) == '(') {
                open++;
            }
            else {
                close = 1;
                if (i < s.length() - 1 && s.charAt(i + 1) == ')') {
                    close++;
                    i++;
                }
                cnt += (2 - close);

                if (open == 0) cnt++;
                else open--;
            }
            i++;
        }
        cnt += open * 2;
        return cnt;
    }
}