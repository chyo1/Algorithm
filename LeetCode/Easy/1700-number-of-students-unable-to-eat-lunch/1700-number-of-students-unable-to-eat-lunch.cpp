
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque <bool> foods, humans;

        for(int i = 0; i < students.size(); i++) {
            foods.push_back(sandwiches[i]);
            humans.push_back(students[i]);
        }

        while (foods.size()) {
            bool food = foods.front();
            int humanNum = humans.size();
            
            int cnt = 0;
            while (cnt <= humanNum && food != humans.front()) {
                humans.push_back(humans.front());
                humans.pop_front();
                cnt++;
            }
            
            if (cnt == humanNum + 1)
                break ;
            
            humans.pop_front();
            foods.pop_front();
            
            printf("%d %d \n", foods.size(), students.size());
        }
        
        return humans.size();
    }
};