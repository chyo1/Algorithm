#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 최대공약수 구하기 (유클리드 호제법)
int getGCD(int a, int b) {
    if (b == 0)
        return a;
    return getGCD(b, a%b);
}

int getArrGCD(vector<int> arr) {
    int gcd;
    
    gcd = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        
        gcd = getGCD(arr[i], gcd);
        
        /* 하나의 원소와도 최대공약수가 존재하지 않는다 
             -> 해당 배열의 숫자 모두를 나눌 수 있는 수가 존재하지 않음 */
        if (gcd == 1)
            return 1;
    }
    return gcd;
}

int checkArrGCD(vector<int> arr, int gcd) {
    for(int i = 0; i < arr.size(); i++) {
        if (arr[i] % gcd == 0)
            return 0;
    }
    return gcd;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int gcdA = 1, gcdB = 1;
    
    // A, B 배열의 최대공약수를 구함
    gcdA = getArrGCD(arrayA);
    gcdB = getArrGCD(arrayB);

    if (gcdA > gcdB) {
        if (checkArrGCD(arrayB, gcdA))
            return gcdA;
        else if (gcdB && checkArrGCD(arrayA, gcdB))
            return gcdB;   
        else
            return 0;
    }
    else {
        if(checkArrGCD(arrayA, gcdB))
            return gcdB;
        else if (gcdA && checkArrGCD(arrayB, gcdA))
            return gcdA;  
        else
            return 0;
    }
    return answer;
}