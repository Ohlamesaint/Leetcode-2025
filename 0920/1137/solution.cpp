class Solution {
public:
    int tribonacci(int n) {
        if(n<3) {
            switch(n) {
                case 0:
                return 0;
                case 1:
                return 1;
                case 2:
                return 1;
            }
        }
        int prev1 = 1, prev2 = 1, prev3 = 0;
        for(int i=3; i<=n; i++) {
            int temp = prev1+prev2+prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }
};