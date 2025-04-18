import java.util.*;
class Solution {
    Set<Integer> set = new HashSet<>();
    Map<Integer, List<Integer>> graph;
    int forward = 0, reverse = 0;
    
    public int[] solution(int[] nodes, int[][] edges) {
        int[] answer = new int[]{0, 0};
        
        graph = new HashMap<>();
        
        // 그래프 정보 생성
        for (int node : nodes) {
            graph.put(node, new ArrayList<>());
        }
        
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }   

        // 홀짝 확인
        for (int node : nodes) {
            if (set.contains(node)) continue;
            
            forward = 0;
            reverse = 0;
            bfs(node);
            
            // 역홀짝/홀짝인게 1개만 있다면 해당 노드를 루트로 정해 역홀짝/홀짝 트리로 만들 수 있음
            if (forward == 1) {
                answer[1]++;
            }
            if (reverse == 1) {
                answer[0]++;
            }
        }
        return answer;
    }
    
    // 해당 그래프에 속한 노드 찾기
    private void bfs(int start) {
        Queue<Integer> q = new ArrayDeque<>();
        
        set.add(start);
        q.add(start);
        while (!q.isEmpty()) {
            int now = q.poll();
            
            // 해당 노드의 홀짝 확인
            int nowCnt = graph.get(now).size() - 1;
            if (now % 2 == 0) {
                if (nowCnt % 2 == 0) forward++;
                else reverse++;
            }
            else {
                if (nowCnt % 2 == 1) forward++;
                else reverse++;
            }
            
            List<Integer> kids = graph.get(now);
            
            for (int kid : kids) {
                if (set.contains(kid)) continue;
                set.add(kid);
                q.add(kid);
                
            }
        }
    }
}