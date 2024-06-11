#include <string>
#include <algorithm>
#include <ctype.h>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    double unionCnt = 0, inter = 0;
    int substrCnt1[26][26] = {0, }, substrCnt2[26][26] = {0, };
    int lenStr1 = str1.size(), lenStr2 = str2.size();
    
    // str1 순회하며 서브 문자열 생성 및 해당 문자열 cnt++
    for (int i = 0; i < lenStr1 - 1; i++) {
        if(isalpha(str1[i]) && isalpha(str1[i + 1])) {
            substrCnt1[tolower(str1[i]) - 'a'][tolower(str1[i + 1]) - 'a']++;
        }
    }
    
    // str2 순회하며 서브 문자열 생성 및 해당 문자열 cnt++
    for (int i = 0; i < lenStr2 - 1; i++) {
        if(isalpha(str2[i]) && isalpha(str2[i + 1])) {
            substrCnt2[tolower(str2[i]) - 'a'][tolower(str2[i + 1]) - 'a']++;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            unionCnt += (substrCnt1[i][j] + substrCnt2[i][j]);
            
            // str1, str2 둘 다 값이 있다면 더 적은 쪽의 문자열 cnt가 교집합
            if (substrCnt1[i][j] && substrCnt2[i][j]) {
                inter += min(substrCnt1[i][j], substrCnt2[i][j]);
                unionCnt -= min(substrCnt1[i][j], substrCnt2[i][j]); // 합집합 - 교집합
            }
        }
    }
    return !unionCnt ? 65536 : (inter * 65536 / unionCnt);
}
