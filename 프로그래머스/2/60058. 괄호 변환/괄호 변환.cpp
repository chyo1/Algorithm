#include <string>
#include <vector>

using namespace std;

bool checkCorrect(string u) {
    int openCnt = 0;
    for (int i = 0; i < u.length(); i++) {
        if (u[i] == '(') openCnt++;
        else openCnt--;
        if (openCnt < 0) return false;
    }
    if (openCnt != 0) return false;

    return true;
}

int getBalanceIdx(string u) {
    int open = 0, close = 0;
    for (int i = 0; i < u.length(); i++) {
        if (u[i] == '(') open++;
        else close++;
        if (open == close) return i + 1;
    }
    return u.length();
}

string getBalance(string w) {
    if (w.empty()) return "";

    int idx = getBalanceIdx(w);
    string u = w.substr(0, idx);
    string v = w.substr(idx);

    if (checkCorrect(u))
        return u + getBalance(v);    
    else {
        string s = "(" + getBalance(v) + ")";
        for (int i = 1; i < u.length() - 1; i++) {
            if (u[i] == '(') s.append(")");
            else s.append("(");
        }
        return s;
    }
}

string solution(string p) {
    return getBalance(p);
}
