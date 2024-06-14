#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int maxPresentCnt = 0;
    int log[50][50] = {0, }, giveCnt[50] = {0, }, receiveCnt[50] = {0, };
    

    int size = gifts.size();
    for (int i = 0; i < size; i++) {
        string now = gifts[i];
        int blankIdx = now.find(' ');
        string giver = now.substr(0, blankIdx), receiver = now.substr(blankIdx + 1);
        
        int giverIdx = find(friends.begin(), friends.end(), giver) - friends.begin();
        int receiverIdx = find(friends.begin(), friends.end(), receiver) - friends.begin();
        
        // 서로 선물을 주고 받은 기록을 표로 옮김       
        log[giverIdx][receiverIdx]++;
        
        // 선물 지수 계산
        giveCnt[giverIdx]++;
        giveCnt[receiverIdx]--;
    }
    
    int people = friends.size();
    for (int i = 0; i < people; i++) {
        for (int j = 0; j < people; j++) {
            if (i == j) continue;
            
            // 선물을 주고 받음 & 주고 받은 횟수가 다름
            if (log[i][j] || log[j][i]) {
                if (log[i][j] > log[j][i])
                    receiveCnt[i]++;
                
                // 선물을 주고 받은 횟수가 같음 & 선물 지수 비교
                else if (log[i][j] == log[j][i] && giveCnt[i] > giveCnt[j])
                    receiveCnt[i]++;
            }
            
            // 선물을 주고 받지 않음
            else {         
                // 서로의 선물 지수가 다름
                if (giveCnt[i] > giveCnt[j])
                    receiveCnt[i]++;
            }
        }
    }
    for (int i = 0; i < people; i++) 
        maxPresentCnt = max(maxPresentCnt, receiveCnt[i]);
    return maxPresentCnt;
}