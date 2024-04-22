class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int load[1001];
        int maxPassengers = -1;

        fill (load, load + 1001, 0);
        for(int i = 0; i < trips.size(); i++) {
            int numPassengers = trips[i][0], start = trips[i][1], end = trips[i][2];
            load[start] += numPassengers;
            load[end] -= numPassengers;
        }

        int nowPassengers = 0;
        for (int i = 0; i <= 1000; i++) {
            nowPassengers += load[i];
            maxPassengers = max(nowPassengers, maxPassengers);
            if (maxPassengers > capacity)
                return false;
        }

        return true;
    }
};