class Solution {
    public int minSwaps(String s) {
        int openCnt = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == ']') {
                if (openCnt == 0)
                    openCnt++;
                else
                    openCnt--;
            }
            else openCnt++;
        }
        return (openCnt + 1) / 2;
    }
}