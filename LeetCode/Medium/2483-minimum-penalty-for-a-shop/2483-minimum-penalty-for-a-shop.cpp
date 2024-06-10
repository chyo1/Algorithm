class Solution {
public:
    int bestClosingTime(string customers) {
        int size = customers.size();
        int penalty = 0;

        int minPenalty = penalty, minPenaltyTime = 0;

        // index를 늘려가며 close 시간을 조정
        for (int i = 0; i < size; i++) {

            // open일 때 Y이면 penalty--, N이면 penalty++
            penalty = customers[i] == 'Y' ? --penalty : ++penalty;

            // 최소 패널티 시점의 시간 저장
            if (minPenalty > penalty) {
                minPenalty = penalty;
                minPenaltyTime = i + 1;
            }
        }
        return minPenaltyTime;
    }
};