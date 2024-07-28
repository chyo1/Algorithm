class Solution {
public:
    static vector<string> makeSubVec(vector<string>& products, string findWord, int wordLen) {
        int len = 0;
        while (len < products.size() && products[len].substr(0, wordLen) == findWord) {
            len++;
        }
        return vector<string>(products.begin(), products.begin() + len);
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;

        int wordLen = searchWord.size();
        for (int i = 0; i < wordLen; i++) {
            string findWord = searchWord.substr(0, i + 1);
            
            // 해당 단어가 들어있는 첫 번째 위치 찾기
            int start = lower_bound(products.begin(), products.end(), findWord) - products.begin();

            // 해당 위치부터 부분벡터 다시 만들기
            products = vector<string> (products.begin() + start, products.end());
            products = makeSubVec(products, findWord, i + 1);

            if (products.size() > 3)
                ans.push_back(vector<string>(products.begin(), products.begin() + 3));
            else
                ans.push_back(products);
        }
        return ans;
    }
};