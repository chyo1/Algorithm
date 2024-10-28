#include <string>
#include <vector>
#include <cmath>
using namespace std;

void up(int& storey, int& answer, int& locVal) {
    storey += locVal;
    answer += 10 - locVal;
}

void down(int& storey, int& answer, int& locVal) {
    storey -= locVal;
    answer += locVal;
}

int solution(int storey) {
    int answer = 0;
    
    while (storey) {
        int locVal = storey % 10;
        
        if (locVal == 5) {
            if (storey % 100 < 50)
                down(storey, answer, locVal);
            else
                up(storey, answer, locVal);
        }
        else if (locVal < 5)
            down(storey, answer, locVal);
        else
            up(storey, answer, locVal);
        
        storey /= 10;
    }
    return answer;
}