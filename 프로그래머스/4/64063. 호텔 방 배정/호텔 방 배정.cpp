#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

unordered_map<long long, long long> checkDup;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for (long long n : room_number) {
        if (checkDup.find(n) == checkDup.end()) {
            checkDup[n] = n + 1;
            answer.push_back(n);
        }
        else {
            vector<long long> tmp;
            
            tmp.push_back(n);
            long long nextRoomNumber = checkDup[n];
            
            while (checkDup.find(nextRoomNumber) != checkDup.end()) {
                tmp.push_back(nextRoomNumber);
                nextRoomNumber = checkDup[nextRoomNumber];
            }
            for (long long next : tmp)
                checkDup[next] = nextRoomNumber + 1;
            
            checkDup[nextRoomNumber] = nextRoomNumber + 1;
            answer.push_back(nextRoomNumber);
        }
    }
    return answer;
}