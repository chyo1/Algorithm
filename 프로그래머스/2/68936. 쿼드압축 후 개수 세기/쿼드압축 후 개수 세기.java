class Solution {
    private int[] answer = {0, 0};
    public int[] solution(int[][] arr) {
        int n = arr.length;
        
        compress(arr, 0, 0, n);
        return answer;
    }
    
    private void compress(int[][] arr, int sr, int sc, int n) {
        int value = arr[sr][sc];
        for (int i = sr; i < sr + n; i++) {
            for (int j = sc; j < sc + n; j++) {
                if (arr[i][j] != value) {
                    n /= 2;
                    compress(arr, sr, sc, n);
                    compress(arr, sr, sc + n, n);
                    compress(arr, sr + n, sc, n);
                    compress(arr, sr + n, sc + n, n);
                    return;
                }
            }
        }
        
        answer[value]++;
    }
}