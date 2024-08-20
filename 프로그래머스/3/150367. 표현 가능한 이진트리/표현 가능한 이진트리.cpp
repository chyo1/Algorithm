#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 2진수 만들기
string makeBinaryNum(long long num) {
    if (!num)
        return "";
    return makeBinaryNum(num / 2) + to_string(num % 2);
}

// 앞에 0 채워서 자릿수 맞추기
void fillZero(string& binary) {
    int len = binary.size(), two = 1;
    
    while (two <= len)
        two *= 2;

    binary.insert(0, max(two - len - 1, 0), '0');
}

bool isAllZero(string& s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1')
            return false;
    }
    return true;
}

bool isPossibleTree(string s) {
    // leaf node
    if (s.size() == 1 || isAllZero(s))
        return true;

    int root = s.size() / 2;
    if (s[root] == '1') {
        if (isPossibleTree(s.substr(0, root)) && isPossibleTree(s.substr(root + 1)))
            return true;
    }
    return false;
}

vector<int> solution(vector<long long> numbers) {
    int size = numbers.size();
    vector<int> answer;
    
    for (int i = 0; i < size; i++) {
        string binary = makeBinaryNum(numbers[i]);
        fillZero(binary);
        
        // cout << binary << endl;
        answer.push_back(isPossibleTree(binary));
    }
    return answer;
}