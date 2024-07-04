class Solution {
public:
    int bulbSwitch(int n) {
        int cnt = 0, num = 0, step = 1;
        while (num < n) {
            cnt++;
            step += 2;
            num += step;
        }
        return cnt;
    }
};
/*
0 - 0
------------ 1
1 - 1
2 - 1
3 - 1
------------- 3
4 - 2
5 - 2
6 - 2
7 - 2
8 - 2
------------- 5
9 - 3
10 - 3
11 - 3
12 - 3
13 - 3
14 - 3
15 - 3
-------------- 7
16 - 4
17 - 4
18 - 4
19 - 4
20 - 4
-------------- 9
25 - 5
*/