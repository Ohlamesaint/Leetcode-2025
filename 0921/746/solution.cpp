#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[n-1];
        int prev1 = cost[n-2];

        for(int i=n-3; i>=0; i--) {
            int temp = cost[i]+min(prev2, prev1);
            prev2 = prev1;
            prev1 = temp;
        }

        return min(prev1, prev2);
        
    }
};