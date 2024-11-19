#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> strToNumList(string s) {
    vector<int> nums;
    
    int start = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            nums.push_back(stoi(s.substr(start, i - start)));
            start = i + 1;
        }
    }
    nums.push_back(stoi(s.substr(start)));
    
    return nums;
}

vector<vector<int>> divideStr(string s) {
    vector<vector<int>> v;
    int start = 2, end = 2;
    
    while (end < s.size()) {
        while (end < s.size() && s[end++] != '}');
        v.push_back(strToNumList(s.substr(start, end - start - 1)));
        start = end + 2;
        end = start;
    }
    return v;
}

bool cmp(vector<int> a, vector<int> b) { return a.size() < b.size(); }

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> v = divideStr(s);
    sort(v.begin(), v.end(), cmp);

    bool visited[100'001] = {0, };
    for (vector<int> nums : v) {
        for (int n : nums) {
            if (visited[n]) continue;
            answer.push_back(n);
            visited[n] = true;
        }
    }
    return answer;
}