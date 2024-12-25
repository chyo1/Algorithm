import java.util.*;

class Solution {
    
    List<String> answer = new ArrayList<>();
    boolean[] visited;

    boolean dfs(String[][] tickets, String now, int cnt) {
        answer.add(now);
        
        if (cnt == tickets.length + 1)
            return true;

        for (int i = 0; i < tickets.length; i++) {
            if (tickets[i][0].equals(now) && !visited[i]) {   
                visited[i] = true;
                if (dfs(tickets, tickets[i][1], cnt + 1)) 
                    return true;
                
                answer.remove(answer.size() - 1);
                visited[i] = false;
            }
        }
        return false;
    }
    
    public String[] solution(String[][] tickets) {
        Arrays.sort(tickets, (a, b) -> {
            if (a[0].equals(b[0])) {
                return a[1].compareTo(b[1]);
            } else {
                return a[0].compareTo(b[0]); 
            }
        });
        visited = new boolean[tickets.length];
        
        dfs(tickets, "ICN", 1);
        return answer.toArray(new String[0]);
    }
}