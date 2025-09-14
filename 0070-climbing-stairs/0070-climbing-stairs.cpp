class Solution {
    int d[46];
public:
    int climbStairs(int n) {
        // dp: end to 1 or 2
        
        d[0] = 1, d[1] = 1;
        for (int i = 2; i <= 45; i++) {
            d[i] = d[i-2] + d[i-1];
        }

        return d[n];
    }
};