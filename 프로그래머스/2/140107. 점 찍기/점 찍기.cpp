#include <string>
#include <vector>
#include <cmath>
#include <stdio.h>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0, x = 0;
    while (x <= d) {
        long long y = sqrt((long long) d * d - (long long) x * x);
        
        answer += y / k + 1;
        x += k;
    }
    return answer;
}