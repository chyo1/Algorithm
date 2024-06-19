class Solution {
    vector<int> ret;
public:
    vector<int> lexicalOrder(int n) {
        int getLen = n, len = 0;

        while (getLen > 0) {
            getLen /= 10;
            len++;
        }
        for (int i = 1; i < 10; i++) {
            int num = i;
            getLexicographicalNum(num, n, 1);
        }
        return ret;
    }
    bool getLexicographicalNum(int num, int n, int len){
        
        for (int i = 0; i < min(len, 10); i++) {
            int number = num + i;
            if (number > n)
                return true;
            ret.push_back(number);
            // printf("num: %d\n", number);
            getLexicographicalNum(number * 10, n, len * 10);
        }
        return false;
    }
};