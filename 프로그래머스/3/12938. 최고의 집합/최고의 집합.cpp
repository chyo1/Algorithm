#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    int div = s / n;
    vector<int> answer(n, s / n);

    if (s % n == 0)
        return answer;

    else {
        int rem = s - s / n * n;
        int idx = answer.size() - 1;
        while (rem--)
            answer[idx--]++;
    }
    if (answer[0])
        return answer;
    return {-1};
}