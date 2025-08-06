import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;

public class Main {
	static int[] population;
	static boolean[] group;
    static int N, ans = 10_000;
    static List<Integer>[] city;
    
    public static void main(String args[]) throws Exception {
    	BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(bf.readLine());
		
    	population = new int[N + 1];
    	group = new boolean[N + 1];
		city = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++)
			city[i] = new ArrayList<>();
		
    	String[] inputs = bf.readLine().split(" ");
		for (int i = 1; i <= N; i++) {
			population[i] = Integer.parseInt(inputs[i - 1]);
		}
		
		for (int i = 1; i <= N; i++) {
			inputs = bf.readLine().split(" ");
			int cnt = Integer.parseInt(inputs[0]);
			
			for (int j = 1; j <= cnt; j++) {
				city[i].add(Integer.parseInt(inputs[j]));
			}
		}
		
		makeGroup(1, 0);

		if (ans == 10_000)
			System.out.println(-1);
		else System.out.println(ans);
    }
    
    static void makeGroup(int now, int size) {
    	if (now == N + 1 || N - 1 <= size) return;
    	for (int i = now; i <= N; i++) {
    		if (size == 0 && N / 2 < i) return;
    		
    		if (group[i]) continue;
    		group[i] = true;
    		
    		// 구역 간 인구 차이 계산
    		if (isDivided(i)) checkDiff();
    		makeGroup(i + 1, size + 1);
    		
    		group[i] = false;
    	}
    }
    
    static void checkDiff() {
    	int s1 = 0;
    	int s2 = 0;
    	for (int i = 1; i <= N; i++) {
    		if (group[i]) s1 += population[i];
    		else s2 += population[i];
    	}
    	ans = Math.min(Math.abs(s1 - s2), ans);
    }
    
    static boolean isDivided(int in) {
    	boolean[] visited = new boolean[N + 1];

    	// 묶인 도시들이 같은 그룹으로 묶이는 지 확인
    	Queue<Integer> q = new ArrayDeque<>();
    	q.add(in);
    	visited[in] = true;
    	while (!q.isEmpty()) {
    		int now = q.poll();
    		if (city[now].isEmpty()) continue;
    		
    		for (int next : city[now]) {
    			if (group[next] && !visited[next]) {
    				q.add(next);
    				visited[next] = true;
    			}
    		}
    	}
    	
    	int out = 0;
    	for (int i = 1; i <= N; i++) {
    		if (!group[i]) out = i;
    		if (group[i] && visited[i] != true)
    			return false;
    	}
    	
    	// 묶이지 않은 도시들이 같은 그룹에 묶여 있는지 확인
    	Arrays.fill(visited, false);
    	q.add(out);
    	visited[out] = true;
    	while (!q.isEmpty()) {
    		int now = q.poll();
    		if (city[now].isEmpty()) continue;
    		
    		for (int next : city[now]) {
    			if (!group[next] && !visited[next]) {
    				q.add(next);
    				visited[next] = true;
    			}
    		}
    	}
    	
    	for (int i = 1; i <= N; i++) {
    		if (!group[i] && visited[i] != true)
    			return false;
    	}
    	return true;
    }

}
