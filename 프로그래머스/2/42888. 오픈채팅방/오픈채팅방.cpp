#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
vector<string> parse(string str) {
    vector<string> strs;
    
    int idx = 0, len = 0;
    for (char c : str) {
        if (c == ' ') {
            strs.push_back(str.substr(idx, len));
            cout << str.substr(idx, len) << endl;
            idx += len;
            len = 0;
        }
        else
            len++;
        // cout << c << endl;
    }
    strs.push_back(str.substr(idx, len));
    return strs;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> info;
    
    for (string r : record) {
        parse(r);    
    }
    
    return answer;
}