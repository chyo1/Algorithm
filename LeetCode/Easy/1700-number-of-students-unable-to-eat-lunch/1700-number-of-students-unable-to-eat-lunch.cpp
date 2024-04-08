class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque <bool> foods, humans;

        // 자료들을 deque에 담음
        for(int i = 0; i < students.size(); i++) {
            foods.push_back(sandwiches[i]);
            humans.push_back(students[i]);
        }

        while (foods.size()) {
            bool food = foods.front();
            int humanNum = humans.size();
            
            int cnt = 0;

            // 모든 학생들을 탐색했음 or 현재 학생이 먹을 샌드위치와 일치할 때까지
            while (cnt <= humanNum && food != humans.front()) {
                humans.push_back(humans.front());
                humans.pop_front();
                cnt++;
            }
            
            // 모든 학생을 다 탐색함 -> 먹을 수 있는 샌드위치 없음
            if (cnt == humanNum + 1)
                break ;
            
            // 학생과 샌드위치 없앰
            humans.pop_front();
            foods.pop_front();
        }
        
        return humans.size();
    }
};