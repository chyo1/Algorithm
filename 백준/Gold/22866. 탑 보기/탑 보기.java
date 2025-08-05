import java.util.*;
import java.io.*;

class Main {

    public static void main(String args[]) throws Exception {
    	BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    		
		int N = Integer.parseInt(bf.readLine());
		String[] inputs = bf.readLine().split(" ");
		int[] nums = new int[N];
		Cor[] records = new Cor[N];
		for (int i = 0; i < N; i++) {
			nums[i] = Integer.parseInt(inputs[i]);	
			records[i] = new Cor();
		}
		
		
		Deque<Integer> s = new ArrayDeque<>();
		
		s.push(0);
		for (int i = 1 ; i < N; i++) {
			while (!s.isEmpty() && nums[s.peek()] <= nums[i]) {
				int now = s.pop();
				if (!s.isEmpty()) records[now].cnt += s.size();
				if (!s.isEmpty() && Math.abs(records[now].nearest - now) > Math.abs(now - s.peek())) {
					records[now].nearest = s.peek();
				}
			} 
			s.push(i);
		}
		
		while (!s.isEmpty()) {
			int now = s.pop();
			if (!s.isEmpty()) records[now].cnt += s.size();
			if (!s.isEmpty() && Math.abs(records[now].nearest - now) > Math.abs(now - s.peek())) {
				records[now].nearest = s.peek();
			}
		}
		
		s.clear();
		s.push(N - 1);
		for (int i = N - 2; i >= 0; i--) {
			while (!s.isEmpty() && nums[s.peek()] <= nums[i]) {
				int now = s.pop();
				if (!s.isEmpty()) records[now].cnt += s.size();
				if (!s.isEmpty() && Math.abs(records[now].nearest - now) > Math.abs(now - s.peek())) {
					records[now].nearest = s.peek();
				}
			} 
			s.push(i);
		}
		
		while (!s.isEmpty()) {
			int now = s.pop();
			if (!s.isEmpty()) records[now].cnt += s.size();
			if (!s.isEmpty() && Math.abs(records[now].nearest - now) > Math.abs(now - s.peek())) {
				records[now].nearest = s.peek();
			}
		}
		
		for (int i = 0; i < N; i++) {
			if (records[i].cnt != 0) 
				System.out.println(records[i].cnt + " " + (records[i].nearest + 1));
			else {
				System.out.println("0");
			}
		}
		
    }
    
    static class Cor {
    	int cnt = 0;
    	int nearest = -200_000;
    	
		public Cor() {
			super();
		}
    }
    

 
}
