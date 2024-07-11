class Solution {
private:
    int line[10] = {0, };
    bool visited[10] = {false, };
    
public:
    vector<vector<string>> ans;

    vector<vector<string>> solveNQueens(int n) {
        getNQueens(1, n);
        return ans;
    }

    // 각 케이스를 답 벡터에 추가
    void makeAns(int n) {
        vector<string> caseOne;
        for (int i = 1; i <= n; i++) {
            string row ;
            for (int j = 1; j <= n; j++) {
                row += ((line[i] == j) ? 'Q' : '.');
            }
            caseOne.push_back(row);
        }
        ans.push_back(caseOne);
    }

    // 대각선 상에 값이 존재하는지 확인
    bool isPossibleLine(int val, int end) {
        for (int i = 1; i < end; i++) {
            // row 차이 == col 차이 : 같은 대각선 상에 존재
            if (abs(val - line[i]) == abs(end - i))
                return false;
        }
        return true;
    }

    void getNQueens(int col, int n) {

        // 표를 다 채웠다면 답에 추가
        if (col == n + 1) {
            makeAns(n);
            return ;
        }
        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;

            if (col == 1 || isPossibleLine(i, col)) {
                visited[i] = true;
                line[col] = i;
                getNQueens(col + 1, n);
                visited[i] = false;
            }
        }
    }
};
