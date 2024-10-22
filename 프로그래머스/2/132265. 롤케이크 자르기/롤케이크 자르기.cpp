#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0, size = topping.size();
    int frontSum[10001] = {0, }, frontCnt = 0;
    
    for (int i = 0; i < size; i++) {
        int top = topping[i];
        frontSum[top]++;
        if (frontSum[top] == 1) frontCnt++;
    }
    
    int backSum[10001] = {0, }, backCnt = 0;
    for (int i = size - 1; i > 0; i--) {
        int top = topping[i];
        backSum[top]++; frontSum[top]--;
        
        if (frontSum[top] == 0) frontCnt--;
        if (backSum[top] == 1) backCnt++;
        
        if (frontCnt == backCnt)
            answer++;
    }
    return answer;
}