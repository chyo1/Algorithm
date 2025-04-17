import java.util.*;
class Solution {
    public int[][] solution(int[][] data, String ext, int val_ext, String sort_by) {
        int[][] answer = {};
        List<int[]> ans = new ArrayList<>();
        
        int extIdx = 0;
        if (ext.equals("code")) {
            extIdx = 0;
        } else if (ext.equals("date")) {
            extIdx = 1;
        } else if (ext.equals("maximum")) {
            extIdx = 2;
        } else {
            extIdx = 3;
        }
        
        int sortIdx = 0;
        if (sort_by.equals("code")) {
            sortIdx = 0;
        } else if (sort_by.equals("date")) {
            sortIdx = 1;
        } else if (sort_by.equals("maximum")) {
            sortIdx = 2;
        } else {
            sortIdx = 3;
        }
        
        for (int i = 0; i < data.length; i++) {
            if (data[i][extIdx] < val_ext) ans.add(data[i]);
        }
        final int sortIndex = sortIdx;
        ans.sort(Comparator.comparingInt(a -> a[sortIndex]));
        
        return ans.toArray(new int[ans.size()][]);
    }
}