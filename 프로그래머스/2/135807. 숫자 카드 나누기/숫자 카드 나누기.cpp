#include <vector>
#include <algorithm>
using namespace std;

int getGCD(int a, int b) {
    if (b == 0)
        return a;
    return getGCD(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int gcdA = arrayA[0], gcdB = arrayB[0];
    int answer = 0;
    
    for (int i = 1; i < arrayA.size(); i++)
        gcdA = getGCD(gcdA, arrayA[i]);
    
    for (int i = 1; i < arrayB.size(); i++)
        gcdB = getGCD(gcdB, arrayB[i]);
    
    int i;
    for (i = 0; i < arrayA.size(); i++) {
        if (arrayA[i] % gcdB == 0) break;
    }
    if (i == arrayA.size())
        answer = gcdB;
    
    for (i = 0; i < arrayB.size(); i++) {
        if (arrayB[i] % gcdA == 0) break;
    }
    if (i == arrayB.size())
        answer = max(gcdA, answer);
    
    return answer;
}