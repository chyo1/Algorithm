class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;

        int wordLen = searchWord.size(), listCnt = products.size();
        for (int i = 0; i < wordLen; i++) {

            // 해당 단어가 들어있는 첫 번째 위치 찾기
            int start = lower_bound(products.begin(), products.end(), searchWord.substr(0, i + 1)) - products.begin();
            
            // 해당 위치 + 2개, 주어진 배열의 마지막 원소 중 작은 인덱스 찾기
            int end = min(listCnt - 1, start + 2);

            // 겹치는 단어가 있을 때까지 end--
            while (start <= end && products[end].substr(0, i + 1) != searchWord.substr(0, i + 1)){
                end--;
            };

            // 답 만들기
            vector<string> sub;
            for (int j = start; j <= end; j++)
                sub.push_back(products[j]);
            ans.push_back(sub);
        }
        return ans;
    }
};