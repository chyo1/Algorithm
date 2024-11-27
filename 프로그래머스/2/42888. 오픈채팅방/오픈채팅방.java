import java.util.*;

class Solution {
    private HashMap<String, String> info = new HashMap<String, String>();
    private List<String[]> prints = new ArrayList<String[]>();
    
    public String[] parse(String str) {
        return str.split(" ");
    }
    
    public void updateInfo(String[] strs) {
        String command = strs[0], uid = strs[1];
        
        if (command.equals("Enter")) {
            String[] print = {uid, "님이 들어왔습니다."};
            prints.add(print);
            info.put(uid, strs[2]);
        }
        
        else if (command.equals("Leave")) {
            String[] print = {uid, "님이 나갔습니다."};
            prints.add(print);
        }
            
        else
            info.put(uid, strs[2]);
    }
    
    public String[] solution(String[] record) {
        
        for (String r : record) {
            String[] str = parse(r);
            updateInfo(str);
        }
        
        String[] answer = new String[prints.size()];
        
        int idx = 0;
        for (String[] print : prints) {
            String p = info.get(print[0]) + print[1];
            answer[idx++] = p;
        }
        return answer;
    }
}