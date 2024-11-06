#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0, size = queue1.size();
    ll sum1 = 0, sum2 = 0;

    queue<int> q1, q2;
    
    for (int i = 0; i < size; i++) {
        sum1 += queue1[i];  q1.push(queue1[i]);
        sum2 += queue2[i];  q2.push(queue2[i]);
    }
    
    if ((sum1 + sum2) % 2)
        return -1;
    
    long long maxCnt = 4 * size;
    while (maxCnt--) {
        if (sum1 == sum2)
            return answer;
        
        if (q1.empty() || q2.empty())
            break;
    
        if (sum1 < sum2) {
            int tmp = q2.front();
            q2.pop();   q1.push(tmp);
            sum1 += tmp; sum2 -= tmp;
        }
        else {
            int tmp = q1.front();
            q1.pop(); q2.push(tmp);
            sum1 -= tmp; sum2+= tmp;
        }
        answer++;
    }
    return -1;
}
