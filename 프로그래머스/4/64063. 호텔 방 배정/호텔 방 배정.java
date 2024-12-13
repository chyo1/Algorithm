import java.util.*;

class Solution {
    public long[] solution(long k, long[] room_number) {
        long[] answer = new long[room_number.length];
        
        HashMap<Long, Long> checkDup = new HashMap<>();
        
        for (int i = 0; i < room_number.length; i++) {
            long r = room_number[i];
            if (checkDup.containsKey(r)) {
                List<Long> tmp = new LinkedList<>();
                tmp.add(r);
                
                Long next = checkDup.get(r);
                while (checkDup.containsKey(next)) {
                    tmp.add(next);
                    next = checkDup.get(next);
                }

                for (long t : tmp)
                    checkDup.put(t, next + 1);
                    
                checkDup.put(next, next + 1);
                answer[i] = next;
            }  
            
            else {
                checkDup.put(r, r + 1);
                answer[i] = r;
            }
        }
        return answer;
    }
}