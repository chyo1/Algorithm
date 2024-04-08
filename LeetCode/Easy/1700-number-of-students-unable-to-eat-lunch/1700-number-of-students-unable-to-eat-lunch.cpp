#define SQUARE 0
#define CIRCLE 1

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cir = 0, squ = 0, size = students.size();
        
        for (int i = 0; i < students.size(); i++) {
            if (students[i] == SQUARE)
                squ++;
            else
                cir++;
        }
        
        for (int i = 0; i < students.size(); i++) {
            if (sandwiches[i] == CIRCLE) {
                if (cir)
                    cir--;
                else
                    break ;
            }
            else {
                if (squ)
                    squ--;
                else
                    break;
            }
        }
        return cir + squ;
    }
};