#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> info;
vector<pair<string, string>> print;

vector<string> parse(string str) {
    vector<string> strs;
    
    int idx = 0, len = 0;
    for (char c : str) {
        if (c == ' ') {
            strs.push_back(str.substr(idx, len));
            idx += len + 1;
            len = 0;
        }
        else
            len++;
    }
    strs.push_back(str.substr(idx, len));
    return strs;
}

void updateInfo(vector<string> strs) {
    string command = strs[0], uid = strs[1];
    
    if (command == "Enter") {
        print.push_back({uid, "님이 들어왔습니다."});
        info[uid] = strs[2];
    }
    
    else if (command == "Leave")
        print.push_back({uid, "님이 나갔습니다."});
    
    else if (command == "Change")
        info[uid] = strs[2];
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for (string r : record) {
        vector<string> strs = parse(r);   
        updateInfo(strs);
    }
    
    for (auto p : print)
        answer.push_back(info[p.first] + p.second);
    
    return answer;
}