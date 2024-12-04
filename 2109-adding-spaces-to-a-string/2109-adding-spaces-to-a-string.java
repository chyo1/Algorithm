class Solution {
    public String addSpaces(String s, int[] spaces) {
        char[] ans = new char[s.length() + spaces.length];

        int idx = 0, spaceIdx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (spaceIdx < spaces.length && i == spaces[spaceIdx]) {
                ans[idx++] = ' ';
                spaceIdx++;
            }
            ans[idx++] = s.charAt(i);
        }
        return new String(ans);
    }
}