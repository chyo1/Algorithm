#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int percents[5] = {0, 10, 20, 30, 40};
int sales[7];
vector<int> answer(2, 0);

void calculateMaxResults(vector<vector<int>>& users, vector<int>& emoticons) {
    int total = 0, plusUsers = 0;
    
    for (int i = 0; i < users.size(); i++) {
        int amount = 0;
        for (int j = 0; j < emoticons.size(); j++) {
            if (users[i][0] <= sales[j])
                amount += emoticons[j] * (100 - sales[j]) / 100;
            
            if (users[i][1] <= amount) {
                plusUsers++;
                break;
            }
        }
        if (amount < users[i][1]) {
            total += amount;
        }
    }
    
    if (answer[0] < plusUsers) {
        answer[0] = plusUsers;
        answer[1] = total;
    }
    else if (answer[0] == plusUsers) {
        answer[1] = max(answer[1], total);
    }
}

void getAllSales(vector<vector<int>>& users, vector<int>& emoticons, int nowIdx) {
    if (nowIdx == emoticons.size()) {
        calculateMaxResults(users, emoticons);
        return;
    }
    for (int i = 0; i < 5; i++) {
        sales[nowIdx] = percents[i];
        getAllSales(users, emoticons, nowIdx + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    getAllSales(users, emoticons, 0);
    return answer;
}