class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        // numberOfUnitsPerBox 기준 내림차순 정렬
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &a, vector<int> &b){
            return a[1] > b[1];
        });

        // numberOfUnitsPerBox가 큰 것부터 차례로 넣어 maximumUnits 도출
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