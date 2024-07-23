class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int size = plants.size(), half = size / 2;
        int cntA = 0, cntB = 0, capA = capacityA, capB = capacityB;

        for (int i = 0; i < half; i++) {
            if (capA >= plants[i])
                capA -= plants[i];
            else {
                cntA++;
                capA = capacityA - plants[i];
            }
        }

        // if (size % 2) {
            for (int i = size - 1; i >= half + 1; i--) {
                if (capB >= plants[i])
                    capB -= plants[i];
                else {
                    cntB++;
                    capB = capacityB - plants[i];
                }
            }

        if (size % 2) {
            if (capA < capB) {
                if (capB < plants[half])
                    cntB++;
            }
            else {
                if (capA < plants[half])
                    cntA++;
            }
        }
        else {
            if (capB >= plants[half])
                capB -= plants[half];
            else {
                cntB++;
                capB = capacityB - plants[half];
            }
        }
        return cntA + cntB;
    }
};