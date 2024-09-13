#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int videoLen, nowLoc, opStart, opEnd, loc;
    
    // 초 단위로 맞추기 & 정수형 변환
    loc = video_len.find(':');
    videoLen = stoi(video_len.substr(0, loc)) * 60 + stoi(video_len.substr(loc + 1));
    
    loc = pos.find(':');
    nowLoc = stoi(pos.substr(0, loc)) * 60 + stoi(pos.substr(loc + 1));
    
    
    loc = op_start.find(':');
    opStart = stoi(op_start.substr(0, loc)) * 60 + stoi(op_start.substr(loc + 1));
    
    loc = op_end.find(':');
    opEnd = stoi(op_end.substr(0, loc)) * 60 + stoi(op_end.substr(loc + 1));
    
    // prev, next
    for (string cmd : commands) {
        // 오프닝 건너뛰기
        if (opStart <= nowLoc && nowLoc <= opEnd)
            nowLoc = opEnd;
        
        if (cmd == "prev")
            nowLoc = max(0, nowLoc - 10);
        
        else if (cmd == "next")
            nowLoc = min(nowLoc + 10, videoLen);
    }
    
    // 오프닝 건너뛰기
    if (opStart <= nowLoc && nowLoc <= opEnd)
        nowLoc = opEnd;
        
    
    int min = nowLoc / 60, sec = nowLoc % 60;
    answer = min < 10 ? "0" + to_string(min) : to_string(min);
    answer += ":";
    answer += sec < 10 ? "0" + to_string(sec) : to_string(sec);

    return answer;
}