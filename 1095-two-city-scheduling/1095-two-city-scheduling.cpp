class Solution {
public:

    static bool cmp(vector<int> a, vector<int> b) {
        return (a[0] - a[1]) < (b[0] - b[1]);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum = 0;
        int size = costs.size(), n = size / 2;
        sort(costs.begin(), costs.end(), cmp);

        for (int i = 0; i < size; i++) {
            // printf("a: %d b: %d diff: %d\n", costs[i][0], costs[i][1], costs[i][0] - costs[i][1]);
            sum += costs[i][i / n];
        }
        return sum;
    }
};