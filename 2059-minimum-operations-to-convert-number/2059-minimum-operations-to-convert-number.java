class Solution {
    public int minimumOperations(int[] nums, int start, int goal) {
        Queue<Integer> q = new ArrayDeque<>();

        boolean[] visited = new boolean[1001];
        int steps = 1;

        visited[start] = true;
        q.add(start);
        while (!q.isEmpty()) {
            int size = q.size();
            
            while (size-- > 0) {
                int now = q.poll();

                for (int n : nums) {
                    for (int next : new int[]{now + n, now - n, now ^ n}) {
                        if (0 <= next && next <= 1000 && !visited[next]) {
                            q.add(next);
                            visited[next] = true;
                        }

                        if (next == goal) return steps;
                    }
                }
            }

            steps++;
        }
        return -1;
    }
}