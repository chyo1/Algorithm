#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int size = numbers.size();
    vector<int> answer(size);
    stack<int> bigValue;
    
    // init
    answer[size - 1] = -1;
    bigValue.push(numbers[size - 1]);
    
    for (int i = size - 2; i >= 0; i--) {
        
        while (bigValue.size() && numbers[i] >= bigValue.top())
            bigValue.pop();
        
        if (bigValue.empty())
            answer[i] = -1;
        else
            answer[i] = bigValue.top();
        bigValue.push(numbers[i]);
    }
    return answer;
}