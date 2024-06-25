class Solution {
public:
    #define MAX_VAL 100001
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int arr[MAX_VAL] = {0, };
        bool checkSameRange[MAX_VAL] = {false, };
        vector<vector<int>> answer;

        for (int i = 0; i < intervals.size(); i++) {
            vector<int> now = intervals[i];

            // 시작 지점 증가, 종료 지점 감소
            if (now[0] != now[1])
                arr[now[0]]++, arr[now[1]]--;
            else
                checkSameRange[now[0]] = true;
        }

        // 새로 입력된 간격 추가
        if (newInterval[0] != newInterval[1])
            arr[newInterval[0]]++, arr[newInterval[1]]--;
        else
            checkSameRange[newInterval[0]] = true;

        int start, end, nowVal;
        for (int i = 0; i < MAX_VAL; i++) {

            if (checkSameRange[i] && !arr[i]) {
                // 해당 구간 추가
                vector<int> element = {i, i};
                answer.push_back(element);
            }

            // 시작지점
            if (arr[i] > 0) {
                start = i;
                nowVal = arr[i];

                // 해당 구간이 끝날 때까지
                while (nowVal != 0) {
                    // if (checkSameRange[i]) {
                    //     vector<int> element = {start, i};
                    //     answer.push_back(element);
                    //     start = i;
                    // }
                    nowVal += arr[++i];
                }

                // 해당 구간 추가
                vector<int> element = {start, i};
                answer.push_back(element);
            }

        }
        return answer;
    }
};