#include <string>
#include <algorithm>
#include <ctype.h>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    int answer = 65536;
    double total = 0, count = 0;
    
    // int sub1[700] = {0, }, sub2[700] = {0, };
    int sub1[26][26] = {0, }, sub2[26][26] = {0, };
    
    int lenStr1 = str1.size(), lenStr2 = str2.size();
    for (int i = 0; i < lenStr1 - 1; i++) {
        if(isalpha(str1[i]) && isalpha(str1[i + 1])) {
            sub1[tolower(str1[i]) - 'a'][tolower(str1[i + 1]) - 'a']++;
             
            // string s;
            // s += tolower(str1[i]);
            // s += tolower(str1[i + 1]);
            // cout << s << endl;

        }
    }
    
    for (int i = 0; i < lenStr2 - 1; i++) {
        if(isalpha(str2[i]) && isalpha(str2[i + 1])) {
            sub2[tolower(str2[i]) - 'a'][tolower(str2[i + 1]) - 'a']++;
            
            
            // string s;
            // s += tolower(str2[i]);
            // s += tolower(str2[i + 1]);
            // cout << s << endl;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            total += (sub1[i][j] + sub2[i][j]);
            if (sub1[i][j] && sub2[i][j]) {
                count += min(sub1[i][j], sub2[i][j]);
                total -= min(sub1[i][j], sub2[i][j]);
            }
        }
    }
    // if (!total)
    //     return answer;
    // answer = (count * 65536 / total);
    return !total ? answer : (count * 65536 / total);
}
