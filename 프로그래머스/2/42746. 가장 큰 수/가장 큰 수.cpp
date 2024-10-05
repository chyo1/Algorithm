#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    return (a + b) > (b + a);
}

string solution(vector<int> numbers) {
    string answer = "";
    int size = numbers.size();
    
    vector<string> str(size);
    for (int i = 0; i < size; i++)
        str[i] = to_string(numbers[i]);
    
    sort(str.begin(), str.end(), cmp);
    
    if (str[0] == "0")
        return "0";
    for (int i = 0; i < size; i++) {
        answer += str[i];
    }
    return answer;
}