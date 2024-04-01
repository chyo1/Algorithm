#include <stdio.h>
int main(){
    int x, y, w, h;
    int xmin, ymin;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    xmin = x < w-x ? x : w-x;
    ymin = y < h-y ? y : h-y;
    if (xmin < ymin) printf("%d", xmin);
    else printf("%d", ymin);
    return 0;
}