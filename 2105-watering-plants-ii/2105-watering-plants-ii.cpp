class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int size = plants.size(), half = size / 2;
        int cntA = 0, cntB = 0, capA = capacityA, capB = capacityB, idxA = 0, idxB = size - 1;

        while (idxB - idxA > 0) {
            if (capA >= plants[idxA])
                capA -= plants[idxA];
            else {
                cntA++;
                capA = capacityA - plants[idxA];
            }

            if (capB >= plants[idxB])
                capB -= plants[idxB];
            else {
                cntB++;
                capB = capacityB - plants[idxB];
            }
            idxA++; idxB--;
        }

        if (idxB == idxA) {
            if (capA < capB) {
                if (capB < plants[idxA])
                    cntB++;
            }
            else {
                if (capA < plants[idxA])
                    cntA++;
            }
        }

        return cntA + cntB;
    }
};