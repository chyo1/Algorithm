#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;
typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0, size = queue1.size(), totalSize = size * 2;
    ll sum1 = 0, sum2 = 0;

    vector<int> v;
    int first = 0, last = size;
    
    // 각 배열의 합 구한 후, 주어진 배열을 벡터로 이동
    for (int i = 0; i < size; i++) {
        sum1 += queue1[i];  v.push_back(queue1[i]);
    }
    for (int i = 0; i < size; i++) {
        sum2 += queue2[i];  v.push_back(queue2[i]);
    }
    
    // 모든 수의 합이 홀수
    if ((sum1 + sum2) % 2)
        return -1;
    
    long long maxCnt = 4 * size;
    while (maxCnt--) {
        
        // 두 큐의 합이 같다면 return
        if (sum1 == sum2)
            return answer;
    
        if (sum1 < sum2) {
            int tmp = v[last];
            sum1 += tmp; sum2 -= tmp;
            last = (last + 1) % totalSize;
        }
        else {
            int tmp = v[first];
            sum1 -= tmp; sum2 += tmp;
            first = (first + 1) % totalSize;
        }
        answer++;
    }
    return -1;
}
