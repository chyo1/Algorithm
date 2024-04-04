#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, int a, int b)
{
    int round = 1;

    if (a > b) swap(a, b);

    while (1) {
       if (b - a == 1 && a % 2 && b % 2 == 0)
           break ;
        a = (a + 1) / 2;
        b = (b + 1) /2;
        round++;  
    }

    return round;
}