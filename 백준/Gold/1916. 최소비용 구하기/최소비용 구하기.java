import java.util.*;
import java.io.*;
public class Main {
	static int N, M;
	static List<int[]>[] costs;
	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(bf.readLine());
		M = Integer.parseInt(bf.readLine());
		
		costs = new List[N + 1];
		for (int i = 1; i <= N ; i++) {
			costs[i]= new ArrayList<int[]>(); 
		}
		for (int i = 0; i < M; i++) {
			String[] inputs = bf.readLine().split(" ");
			int s = Integer.parseInt(inputs[0]);
			int e = Integer.parseInt(inputs[1]);
			int cost = Integer.parseInt(inputs[2]);
			costs[s].add(new int[] {e, cost}); 
		}
		
		String[] inputs = bf.readLine().split(" ");
		int s = Integer.parseInt(inputs[0]);
		int e = Integer.parseInt(inputs[1]);
		
		boolean[] visited = new boolean[N + 1];
		PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> Integer.compare(a[1], b[1]));
		q.add(new int[] {s, 0});
		
		while (!q.isEmpty()) {
			int[] now = q.poll();
			int loc = now[0];
			int cost = now[1];
			if (visited[loc]) continue;
			visited[loc] = true;
			
			if (loc == e) {
				System.out.println(cost);
				return;
			}
			for (int[] next : costs[loc]) {
				int nextLoc = next[0];
				int nextCost = next[1];
				
				if (visited[nextLoc]) continue;
				q.add(new int[] {nextLoc, cost + nextCost});
			}
		}
	}

}
