class Solution {
public:
    int climbStairs(int n) {
        if(n<2) return 1;
        int last = 1;
        int lastTwo = 1;
    
        for(int i=2; i<=n; i++) {
            int temp = last + lastTwo;
            lastTwo = last;
            last = temp;
        }
        return last;
    }
};