#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<2) return nums[0];
        int prev1 = max(nums[0], nums[1]), prev2 = nums[0];
        for(int i=2; i<nums.size(); i++) {
            int temp = max(nums[i]+prev2, prev1);
            prev2 = prev1;
            prev1 = temp;
        }
        return max(prev1, prev2);
    }
};