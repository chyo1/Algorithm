class Solution {
    public int solution(int[] a) {
        int n = a.length;
        int[] cnt = new int[n];
        
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
        }
        
        int maxCnt = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] <= maxCnt) continue;
            
            int count = 0;
            for (int j = 0; j < n - 1; j++) {
                if ((a[j] == i || a[j + 1] == i) && a[j] != a[j + 1]) {
                    count++;
                    j++;
                }
            }
            maxCnt = Math.max(maxCnt, count);
        }
        return maxCnt * 2;
    }
}