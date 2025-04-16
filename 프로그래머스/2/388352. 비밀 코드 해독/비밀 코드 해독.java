class Solution {
    int answer = 0;
    int[] arr = new int[5];
    int[][] questions;
    int[] corrects;
    boolean[] visited;
    
    public int solution(int n, int[][] q, int[] ans) {
        questions = q;
        corrects = ans;
        visited = new boolean[n + 1];
        
        makeCombi(arr, n, 0, 0);
        
        return answer;
    }
    
    private void makeCombi(int[] arr, int n, int idx, int bef) {
        if (idx == 5) {
            if (checkCondition(arr)) {
                answer++;
            }
            return;
        }
        
        for (int i = bef + 1; i <= n; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            arr[idx] = i;
            makeCombi(arr, n, idx + 1, i);
            visited[i] = false;
        }
    }
    
    private boolean checkCondition(int[] arr) {
        for (int i = 0; i < questions.length; i++) {
            if (match(arr, questions[i]) != corrects[i]) {
                return false;
            }
        }
        return true;
    }
    
    private int match(int[] arr, int[] question) {
        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            int now = question[i];
            
            for (int j = 0; j < 5; j++) {
                if (arr[j] == now) cnt++;
            }
            
        }
        return cnt;
    }
}