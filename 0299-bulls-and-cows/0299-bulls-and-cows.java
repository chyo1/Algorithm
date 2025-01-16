class Solution {
    public String getHint(String secret, String guess) {
        int[] cnt = new int[10];
        boolean[] locationA = new boolean[secret.length()];
        
        int countA = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret.charAt(i) == guess.charAt(i)) {
                countA++;
                locationA[i] = true;
            }
            else
                cnt[secret.charAt(i) - '0']++;
        }

        int countB = 0;
        for (int i = 0; i < guess.length(); i++) {
            if (!locationA[i] && 0 < cnt[guess.charAt(i) - '0']) {
                cnt[guess.charAt(i) - '0']--;
                countB++;
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(Integer.toString(countA)).append("A").append(Integer.toString(countB)).append("B");
        return sb.toString();
    }
}