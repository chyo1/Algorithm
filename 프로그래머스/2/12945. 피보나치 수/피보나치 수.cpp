#include <string>
#include <vector>
#define DIV 1234567
using namespace std;

int solution(int n) {
    int answer = 0;
    int Fibo[100001]={0,1,1,};
    for(int i=2;i<=n;i++){
        Fibo[i]=(Fibo[i-1]+Fibo[i-2])%DIV;
    }
    answer=Fibo[n];
    return answer;
}