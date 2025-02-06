#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int H, W, sum = 0;
    int blocks[500];

    scanf("%d %d", &H, &W);
    for (int i = 0; i < W; i++) {
        scanf("%d", &blocks[i]);
    }

    for (int i = 0; i < W; i++) {
        int l = 0, r = 0;
        for (int j = 0; j < i; j++)
            l = max(blocks[j], l);
        for (int j = i; j < W; j++)
            r = max(blocks[j], r);

        if (blocks[i] < l && blocks[i] < r)
            sum += min(l, r) - blocks[i];
    }
    printf("%d", sum);
    return 0;
}