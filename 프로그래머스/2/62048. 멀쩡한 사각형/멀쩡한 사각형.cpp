using namespace std;
// #include <stdio.h>

long long solution(int w,int h) {
    long long answer = 0;
    
    for (double x = 0; x < w; x++) {
        double y = ((double)h * x / (double)w);
        // printf("w = %lf y = %lf\n", x, y);
        answer += (long long) y;
    }
    return answer * 2;    
}
