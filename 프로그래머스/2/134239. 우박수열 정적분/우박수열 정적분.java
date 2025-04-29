import java.util.*;
class Solution {
    private List<Integer> cor = new ArrayList<>();
    private List<Double> sum = new ArrayList<>();
    public double[] solution(int k, int[][] ranges) {
        double[] answer = new double[ranges.length];
        int n = getN(k);
        
        for (int i = 0; i < ranges.length; i++) {
            int[] range = ranges[i];
            int s = range[0];
            int e = n + range[1];
            
            if (e < s)
                answer[i] = -1.0;
            else
                answer[i] = sum.get(e) - sum.get(s);
        }
        return answer;
    }
    
    private int getN(int k) {
        int idx = 0;
        
        double befSum = 0;
        int befK = k;
        sum.add(0.0);
        while (k > 1) {
            cor.add(k);
            if (k % 2 == 0) {
                k /= 2;
            }
            else {
                k = k * 3 + 1;
            }
            idx++;
            double nowSum = (double)(befK + k) / 2 ;
            sum.add(befSum + nowSum);
            befSum += nowSum;
            befK = k;
        }
        return idx;
    }
}