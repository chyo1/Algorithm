#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> income;
    map<string, int> seq;
    
    for (int i = 0; i < enroll.size(); i++) {
        seq[enroll[i]] = i;
        income.push_back(0);
    }
    
    for (int i = 0; i < seller.size(); i++) {
        string nowSeller = seller[i];
        int nowIncome = amount[i] * 100;
        income[seq[nowSeller]] += nowIncome;
        
        while (nowSeller != "-" && nowIncome) {
            string getSeller = referral[seq[nowSeller]];
            
            nowIncome /= 10;
            if (getSeller != "-")
                income[seq[getSeller]] += nowIncome;
            income[seq[nowSeller]] -= nowIncome;
            
            nowSeller = getSeller;
        }
    }
    return income;
}