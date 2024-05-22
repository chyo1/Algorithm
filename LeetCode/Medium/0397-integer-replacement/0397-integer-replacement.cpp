class Solution {
public:
    bool isPlus(long long n) {
        if (n == 3)
            return false;
        long long pNum = n + 1, nNum = n - 1;
        int pCnt = 0, nCnt = 0;
        // printf("pNum: %lld, nNum: %lld\n", pNum, nNum);

        while (pNum != 0) {
            if (pNum & 1)
                pCnt++;
            pNum = pNum >> 1;
        }

        while (nNum != 0) {
            if (nNum & 1)
                nCnt++;
            nNum = nNum >> 1;
        }
        // printf("\np: %d, n: %d\n", pCnt, nCnt);
        return pCnt <= nCnt;
    }

    int integerReplacement(int num) {
        int cnt = 0;
        long long n = num;

        while (n != 1) {
            // printf("n : %d\n", n);
            if (n & 1 == 1) {
                n = isPlus(n) ? n + 1 : n - 1;
                cnt++;
                // printf("odd n : %d\n", n);
            }

            n = n >> 1;
            cnt++;

            // printf("cnt : %d\n", cnt);

        }
        return cnt;
    }
};