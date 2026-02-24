#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int current_jump = 0;
        int current_max = 0;
        int next_max = nums[0];
        for(int i=0; i<nums.size(); i++) {
            if(i>current_max) {
                current_max = next_max;
                current_jump++;
            }
            next_max = max(next_max, i+nums[i]);
        }
        return current_jump;
    }
};