class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;

        int wordLen = searchWord.size(), listCnt = products.size();
        for (int i = 0; i < wordLen; i++) {
            string findWord = searchWord.substr(0, i + 1);
            
            // 해당 단어가 들어있는 첫 번째 위치 찾기
            int start = lower_bound(products.begin(), products.end(), findWord) - products.begin();
            
            // 첫 위치부터 3개 탐색하며 반환할 배열값 찾기
            vector<string> sub;
            for (int j = 0; j < 3; j++) {
                if (start + j >= listCnt) break;
                if (products[start + j].substr(0, i + 1) != findWord)
                    break;
                sub.push_back(products[start + j]);
            }
            ans.push_back(sub);
        }
        return ans;
    }
};