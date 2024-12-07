import java.util.*;

class Solution {
    public int[] solution(String[] gems) {
        int size = gems.length;
        
        Set<String> types = new HashSet<>();
        Map<String, Integer> cntGems = new HashMap<>(); 
        
        for (String gem : gems) {
            types.add(gem);
            cntGems.put(gem, 0);
        }
        int typeCount = types.size();
        
        Set<String> cntTypes = new HashSet<>();
        int start = 0, end = 0, minLen = Integer.MAX_VALUE, minEnd = 0;
        for (String gem : gems) {
            cntTypes.add(gem);
            cntGems.put(gem, cntGems.get(gem) + 1);
            
            if (cntTypes.size() == typeCount) {
                while (start <= end) {
                    int nowGemCount = cntGems.get(gems[start]);
                    if (nowGemCount > 1)
                        cntGems.put(gems[start], nowGemCount - 1);

                    else {
                        if (end - start < minLen) {
                            minLen = end - start;
                            minEnd = end;
                        }
                        break;
                    }
                    start++;
                }
            }
            end++;

        }
        return new int[]{minEnd - minLen + 1, minEnd + 1};
    }
}