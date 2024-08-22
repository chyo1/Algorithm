#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int n) {
    long long step[2000] = {0, };
    step[1] = 1, step[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        step[i] = (step[i - 1] % 1234567 + step[i - 2] % 1234567) % 1234567;
        cout << step[i] << endl;
    }
    return step[n];
}