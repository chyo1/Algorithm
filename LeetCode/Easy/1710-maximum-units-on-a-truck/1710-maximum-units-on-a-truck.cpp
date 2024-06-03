class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &a, vector<int> &b){
            return a[1] > b[1];
        });

        int maxUnits = 0;
        for (int i = 0; i < boxTypes.size(); i++) {
            int cnt = min(boxTypes[i][0], truckSize);

            maxUnits += boxTypes[i][1] * cnt;
            truckSize -= cnt;
            if (!truckSize)
                return maxUnits;
        }
        return maxUnits;
    }
};