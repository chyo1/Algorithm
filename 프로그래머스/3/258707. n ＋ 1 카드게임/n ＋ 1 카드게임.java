import java.util.*;
class Solution {
    public int solution(int coin, int[] cards) {
        Set<Integer> now, next;
        now = new HashSet<>();
        next = new HashSet<>();
        
        int round = 0;
        int n = cards.length;
        
        for (int i = 0; i < n / 3; i++) {
            now.add(cards[i]);
        }
        
        boolean goNext;
        int idx = n / 3;
        while (true) {
            round++;
            if (n <= idx) {
                break;
            }
            
            next.add(cards[idx++]);
            next.add(cards[idx++]);
            goNext = false;
            for (int num : now) {
                if (now.contains(n - num + 1)) {
                    now.remove(num);
                    now.remove(n - num + 1);
                    goNext = true;
                    break;
                }
            }
                
            if (!goNext) {
                if (coin > 0) {
                    for (int num : now) {
                        if (next.contains(n - num + 1)) {
                            now.remove(num);
                            next.remove(n - num + 1);
                            coin--;
                            goNext = true;
                            break;
                        }
                    }
                }
            }
            
            if (!goNext) {
                if (coin > 1) {
                    for (int num : next) {
                        if (next.contains(n - num + 1)) {
                            next.remove(num);
                            next.remove(n - num + 1);
                            coin -= 2;
                            goNext = true;
                            break;
                        }
                    }
                }
            }
            
            if (!goNext) {
                break;
            }
        }
        return round;
    }
}