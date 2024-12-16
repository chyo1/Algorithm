class Solution {
    public int characterReplacement(String s, int k) {
        int l = 0, len = s.length();
        int maxLen = 0, maxAlphaCount = 0;
        
        int[] alpha = new int[26];
        for (int r = 0; r < len; r++) {
            alpha[s.charAt(r) - 'A']++;
            maxAlphaCount = Math.max(maxAlphaCount, alpha[s.charAt(r) - 'A']);

            if ((r - l + 1) - maxAlphaCount > k) {
                alpha[s.charAt(l) - 'A']--;
                l++;
            }
            maxLen = Math.max(maxLen, r - l + 1);

        }
        return maxLen;
    }
}