#include <string>
#include <vector>

using namespace std;

vector<int> answer(2, 0);

void compress(vector<vector<int>>& arr, int sr, int sc, int n) {
    int val = arr[sr][sc];
    for (int i = sr; i < sr + n; i++) {
        for (int j = sc; j < sc + n; j++) {
            if (val != arr[i][j]) {
                n /= 2;
                compress(arr, sr, sc, n);
                compress(arr, sr, sc + n, n);
                compress(arr, sr + n, sc, n);
                compress(arr, sr + n, sc + n, n);
                return;
            }
        }
    }
    answer[val]++;
}

vector<int> solution(vector<vector<int>> arr) {
    int n = arr.size();
    compress(arr, 0, 0, n);
    return answer;
}
