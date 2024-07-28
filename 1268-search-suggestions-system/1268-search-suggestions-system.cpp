class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;

        int wordLen = searchWord.size(), listCnt = products.size();
        for (int i = 0; i < wordLen; i++) {
            int start = lower_bound(products.begin(), products.end(), searchWord.substr(0, i + 1)) - products.begin();
            int end = min(listCnt - 1, start + 2);

            while (start <= end && products[end].substr(0, i + 1) != searchWord.substr(0, i + 1)){
                end--;
            };
            // printf("s: %d, e: %d\n", start, end);
            vector<string> sub;
            for (int j = start; j <= end; j++)
                sub.push_back(products[j]);
            ans.push_back(sub);
        }
        return ans;
    }
};