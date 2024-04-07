class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                cmin++;
                cmax++;
            }
            
            else if (s[i] == ')') {
                cmin--;
                cmax--;
            }
            
            else {
                cmax++; // *을 열린 괄호로 사용
                cmin--; // *을 닫는 괄호로 사용
            }   
            if (cmax < 0) return false; // ( < )
            cmin = max(cmin, 0); // *을 빈문자열 처리
        }
        if (cmin > 0) return false;
        return cmin == 0;
    }
};