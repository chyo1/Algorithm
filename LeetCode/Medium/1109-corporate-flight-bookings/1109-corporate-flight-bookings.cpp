class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        for (int i = 0; i < bookings.size(); i++) {
            int s = bookings[i][0], e = bookings[i][1], seat = bookings[i][2];
            for (int j = s - 1; j < e; j++) {
                res[j] += seat;
            }
        }
        return res;
    }
};