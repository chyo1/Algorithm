class Solution {
public:
    bool canChange(string start, string target) {
        int sIdx = 0, tIdx = 0;
        
        while (tIdx < target.size() || sIdx < start.size()) {
            while (tIdx < target.size() && target[tIdx] == '_') tIdx++;
            while (sIdx < start.size() && start[sIdx] == '_') sIdx++;

            if (target[tIdx] != start[sIdx]) return false;
            
            if (target[tIdx] == 'L' && sIdx < tIdx) return false;
            if (target[tIdx] == 'R' && tIdx < sIdx) return false;
            
            sIdx++;
            tIdx++;
        }

        return true;
    }
};