class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int cnt = 0, now = 0, idx = 1;
        int size = points.size();

        for (int i = 0; i < size; i++)
            printf("%d %d \n", points[i][0], points[i][1]);

        if (size == 1)
            return 1;

        while (now < size) {
            int start = points[now][0], end = points[now][1];
            while (idx < size && !(end < points[idx][0] || points[idx][1] < start)) {
                start = max(start, points[idx][0]);
                end = min(end, points[idx][1]);
                idx++;
            }
            cnt++;
            now = idx, idx += 1;
        }
        return cnt;
    }
};