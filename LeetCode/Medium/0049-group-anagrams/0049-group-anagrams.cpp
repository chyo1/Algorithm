class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        priority_queue <pair<string, string>> pq;

        // 주어진 문자열을 알파벳 순서로 정렬 후 원본 문자열과 함께 우선순위 큐에 저장
        for (int i = 0; i < strs.size(); i++) {
            string origin = strs[i];
            sort(strs[i].begin(), strs[i].end());
            pq.push({strs[i], origin});
        }

        
        while (pq.size()) {
            string cmp = pq.top().first;
            vector<string> anagram;

            // 정렬된 문자열이 같다 == 같은 anagram이므로 해당 값이 같을 때까지 벡터에 넣음
            while (pq.size() && cmp == pq.top().first) {
                anagram.push_back(pq.top().second);
                pq.pop();
            }

            // anagram끼리 묶은 벡터 삽입
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
};