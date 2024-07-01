class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int total[20002] = {0, };
        vector<int> res;
        int size = bookings.size();
        for (int i = 0; i < size; i++) {
            int first = bookings[i][0], last = bookings[i][1], seats = bookings[i][2];
            total[first] += seats;
            total[last + 1] -= seats;
        }

        int flight = 0;
        for (int i = 1; i <= n; i++) {
            flight += total[i];
            res.push_back(flight);
        }
        return res;
    }
};
