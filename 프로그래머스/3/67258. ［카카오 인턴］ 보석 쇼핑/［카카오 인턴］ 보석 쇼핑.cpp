#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> getGemTypeCnt;
    for (string gem : gems)
        getGemTypeCnt.insert(gem);
    
    int typeCnt = getGemTypeCnt.size();
    
    unordered_map<string, int> cntGems;
    set<string> types;
    
    int start = 0, end = 0;
    int minRange = 100'000, minEnd;
    
    while (end < gems.size()) {
        cntGems[gems[end]]++;
        types.insert(gems[end]);
    
        if (types.size() == typeCnt) {
            while (start < end) {
                if (cntGems[gems[start]] > 1) {
                    cntGems[gems[start]]--;
                    start++;
                }
                else break;
            }
            if (minRange > end - start) {
                minRange = end - start;
                minEnd = end;
            }
        }
        end++;
    }
    return {minEnd - minRange + 1, minEnd + 1};
}