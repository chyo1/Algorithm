class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int size = plants.size(), half = size / 2;
        int cnt = 0, capA = capacityA, capB = capacityB, idxA = 0, idxB = size - 1;

        // A 인덱스 증가, B 인덱스 감소시켜가면서 탐색
        while (idxB - idxA > 0) {
            if (capA >= plants[idxA])
                capA -= plants[idxA];
            else {
                cnt++;
                capA = capacityA - plants[idxA];
            }

            if (capB >= plants[idxB])
                capB -= plants[idxB];
            else {
                cnt++;
                capB = capacityB - plants[idxB];
            }
            idxA++; idxB--;
        }

        // 전체 갯수가 홀수일 경우
        if (idxB == idxA) {
            if (capA < capB) {
                if (capB < plants[idxA])
                    cnt++;
            }
            else {
                if (capA < plants[idxA])
                    cnt++;
            }
        }

        return cnt;
    }
};