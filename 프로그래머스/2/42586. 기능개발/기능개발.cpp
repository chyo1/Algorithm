#include <string>
#include <vector>

using namespace std;

#define MAXDAY 1000
typedef pair<int,int> pp;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> Days;
    
    if (progresses.size() < 2) {
        answer.push_back(progresses.size());
        return answer;
    }
    for (int i = 0; i < progresses.size(); i++) {
        int endDay = (100 - progresses[i]);
        if (endDay % speeds[i])
            endDay = endDay / speeds[i] + 1;
        else
            endDay /= speeds[i];
        Days.push_back(endDay);
    }
    
    int proCnt = 1, open = Days[0], i = 1;
    while (i < Days.size()) {
        while (i < Days.size() && Days[i] <= open){
            proCnt++;
            Days[i] = MAXDAY;
            i++;
        }
        answer.push_back(proCnt);
        open = Days[i];
        proCnt = 0;
    }
    
    return answer;
}
