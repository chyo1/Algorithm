#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    stack<int> primary, secondary;
    int ans = 0;
    
    for (int i = order.size(); i >= 1; i--)
        primary.push(i);
    
    while (ans < order.size()) {
        
        // 보조컨테이너 확인
        if (secondary.size() && secondary.top() == order[ans]) {
            ans++;
            secondary.pop();
            continue;
        }
        
        // 주 -> 보조로 옮기며 확인
        while (primary.size() && primary.top() != order[ans]) {
            secondary.push(primary.top());
            primary.pop();
        }
        
        // 주 컨테이너에서 꺼내기
        if (primary.size()) {
            primary.pop();
            ans++;
        }
        else
            return ans;       
    }
    return ans;
}