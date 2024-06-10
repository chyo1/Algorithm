class Solution {
public:
    int bestClosingTime(string customers) {
        int size = customers.size();
        int penalty = 0;
        
        for (int i = 0; i < size; i++) {
            if (customers[i] == 'Y')
                penalty++;
        }

        int minPenalty = penalty, minPenaltyTime = 0;
        for (int i = 0; i < size; i++) {

            penalty = customers[i] == 'Y' ? --penalty : ++penalty;

            if (minPenalty > penalty) {
                minPenalty = penalty;
                minPenaltyTime = i + 1;
            }
        }
        return minPenaltyTime;
    }
};