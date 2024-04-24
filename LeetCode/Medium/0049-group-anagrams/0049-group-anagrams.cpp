class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        unordered_map <string, vector<string>> um;

        // 주어진 문자열을 알파벳 순서로 정렬 후 원본 문자열과 함께 map에 저장
        for (int i = 0; i < strs.size(); i++) {
            
            string origin = strs[i];
            sort(strs[i].begin(), strs[i].end());

            um[strs[i]].push_back(origin);
        }
        
        for (auto iter = um.begin(); iter != um.end(); iter++) {
            anagrams.push_back(iter->second);
        }
        return anagrams;
    }
};