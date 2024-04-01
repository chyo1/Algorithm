#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int A[5], avg=0;
    for(int i=0;i<5;i++){
        scanf("%d",&A[i]);
        avg+=A[i];
    }
    sort(A, A+5);
    printf("%d\n%d",avg/5,A[2]);
    return 0;
}