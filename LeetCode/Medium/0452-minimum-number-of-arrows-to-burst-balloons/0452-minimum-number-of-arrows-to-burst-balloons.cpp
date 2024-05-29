class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 오름차순으로 정렬
        sort(points.begin(), points.end());

        int cnt = 0, now = 0, idx = 1;
        int size = points.size();
        
        while (now < size) {

            // 현재 인덱스 기준으로 end 값 지정
            int end = points[now][1];

            // idx를 늘려가며 end 범위를 좁혀감 -> 하나의 화살을 쏠 때 터뜨릴 수 있는 풍선의 개수 구함
            while (idx < size && end >= points[idx][0]) {
                end = min(end, points[idx][1]);
                idx++;
            }

            cnt++;
            now = idx, idx += 1;
        }
        return cnt;
    }
};