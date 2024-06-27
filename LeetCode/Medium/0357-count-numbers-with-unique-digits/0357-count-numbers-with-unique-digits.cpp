class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int cnt = pow(10, n);
        int min;
        for (int i = 2; i <= n; i++) { // 2-2, 3-2, 3-3
            for (int j = 2; j <= i; j++) {
                min = Combination(i, j) * Permutation(8, i - j) * 9;
                cnt -= min;
                printf("min: %d\n", min);
            }
        }
        return cnt;
    }

    int Combination(int n, int r) {
        int combi = 1;
        for (int i = 0; i < r; i++)
            combi *= n--;
        for (int i = 0; i < r; i++)
            combi /= r--;
        return combi;
    }

    int Permutation(int n, int r) {
        int combi = 1;
        for (int i = 0; i < r; i++)
            combi *= n--;
        return combi;
    }
};
/*
1 - 11,22,33,44,55,66,77,88,99
2 - 3C2 1x1, 11x, x11 : ((8 + 8 + 8) + 1) * 9
3 - 4C2 11xx 1x1x 1xx1 x11x x1x1 xx11
    4C3 111x 11x1 1x11 x111
    4C4 1111
5 - 5C2
...
n - nC2

// sum(n자리에서 같은 수가 2개 이상 들어갈 경우의 수 
    * 나머지 자리가 해당 값 외의 값들로 채워질 경우의 수, 이 때 해당 값들은 같으면 안 됨)
    * 숫자의 범위(1~9)
(nC2 * P(n-2) + nC3 * P(n-3) + ... + nCn) * 9)
*/