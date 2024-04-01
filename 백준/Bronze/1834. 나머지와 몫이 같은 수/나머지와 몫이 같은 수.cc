#include <stdio.h>

int main()
{
    unsigned long long N, ans = 0;
    scanf("%lld", &N);
    for(int i=1;i<N;i++){
       ans += i * N + i;
    }
    printf("%lld", ans);
    return 0;
}