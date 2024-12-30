class Solution {
    boolean[] visited;
    
    private void dfs(int[][] computers, int n, int now) {
        visited[now] = true;
        for (int i = 0; i < n; i++) {
            if (computers[now][i] == 1 && !visited[i])
                dfs(computers, n, i);
        }
    }
    public int solution(int n, int[][] computers) {
        int answer = 0;
        visited = new boolean[n];
        
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            dfs(computers, n, i);
            answer++;
        }
        return answer;
    }
}