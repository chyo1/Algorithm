#define DEL -1

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt = 0;
        stack <int> openLoc, closeLoc;

        for(int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                cnt++;
                openLoc.push(i);
            }

            else if (s[i] == ')') {
                if (openLoc.size() == 0) {
                    closeLoc.push(i);
                }
                else
                    openLoc.pop();
            }   
        }

        while (openLoc.size()) {
            s[openLoc.top()] = DEL;
            openLoc.pop();
        }
        
        while (closeLoc.size()) {
            s[closeLoc.top()] = DEL;
            closeLoc.pop();
        }
        s.erase(remove(s.begin(), s.end(), DEL), s.end());
        return s;    
    }
};
