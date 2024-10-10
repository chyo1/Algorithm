#include <string>
#include <vector>

using namespace std;

string alpha[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

string convert(int target, int base) {
    string str = "";
    
    if (target >= base)
        return convert(target / base, base) + alpha[target % base];
    
    return alpha[target % base];
}

string solution(int n, int t, int m, int p) {
    string answer = "", nums = "";
    
    for (int i = 0; nums.size() < t * m; i++)
        nums += convert(i, n);

    for (int i = p - 1; answer.size() < t; i += m)
        answer += nums[i];
    
    return answer;
}