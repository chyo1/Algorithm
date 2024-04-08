#define SQUARE 0
#define CIRCLE 1

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cir = 0, squ = 0, size = students.size();
        
        // 각 학생이 먹고 싶은 샌드위치의 종류 저장
        for (int i = 0; i < students.size(); i++) {
            if (students[i] == SQUARE)
                squ++;
            else
                cir++;
        }
        
        // 해당 샌드위치를 먹을 학생이 없다면 반환
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