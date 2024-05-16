class Solution {
public:
    int reachNumber(int target) {
        if (target < 0)
            target = -target;
        
        int step = 0, cnt = 0, sum = 0;
        while (sum < target)
            sum += ++step;

        while ((sum - target) % 2 != 0)
            sum += ++step;
        return step;
    }
};