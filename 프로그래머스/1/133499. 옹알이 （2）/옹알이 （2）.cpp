#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

string S[4] = {"aya", "ye", "woo", "ma"};
string dup[4] = {"ayaaya", "yeye", "woowoo", "mama"};
// bool checkDup[4];
int checkS(string s) {
    for(int i = 0; i < 4; i++) {
        if ( s.substr(0, dup[i].size()) == dup[i]) {
            return -1;
        }
    }
    for(int i = 0; i < 4; i++) {
        if (s.substr(0, S[i].size()) == S[i]) {
            // checkDup[i] = true;
            return S[i].size();
        }
    }
    return -1;
}

int solution(vector<string> babbling) {
    int answer = 0;
    int check[31];

    for (int i = 0; i < babbling.size(); i++) {
        
        fill(check, check + 31, false); 
        // fill(checkDup, checkDup + 4, false);
        check[0] = true;
        
        for(int j = 0; j < babbling[i].size(); j++) {
            
            if (check[j]) {
                int findLoc = checkS(babbling[i].substr(j));
                
                if (findLoc >= 0) 
                    check[j + findLoc] = true;
            }
        }
        if (check[babbling[i].size()] == true)
            answer++;
    }
    return answer;
}