class Solution {
public:
    int minimumTotal(vector<vector<int>>& cal) {

        int height = cal.size();

        // 윗 줄의 원소 중 가장 작은 원소의 값을 현재 행에 더 함
        for (int i = 1; i < height; i++) {
            cal[i][0] += cal[i - 1][0];

            for (int j = 1; j < i; j++)
                cal[i][j] += min(cal[i - 1][j - 1], cal[i - 1][j]);

            cal[i][i] += cal[i - 1][i - 1];
        }

        // 마지막 행을 순회하면서 가장 작은 값 구함
        int ans = 2'000'000;
        for (int i = 0; i < height; i++)
            ans = min(ans, cal[height - 1][i]);
        
        return ans;
    }
};