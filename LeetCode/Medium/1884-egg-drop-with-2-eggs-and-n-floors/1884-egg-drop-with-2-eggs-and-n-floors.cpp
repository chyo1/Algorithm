class Solution {
public:
    int twoEggDrop(int n) {
        int step = 0;

        while (n > 0) 
            n -= ++step;

        return step;
    }
};