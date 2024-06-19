class Solution {
    vector<int> ret;
public:
    vector<int> lexicalOrder(int n) {
        string num;
        for (int i = 1; i < 10; i++) {
            num = to_string(i);
            getLexicographicalNum(num, n);
        }
        return ret;
    }
    void getLexicographicalNum(string num, int n){
        if (stoi(num) > n)
            return ;
        ret.push_back(stoi(num));
        for (int i = 0; i < 10; i++) {
            getLexicographicalNum(num + to_string(i), n);
        }
    }
};