#include <vector>

using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int runner = 0;
        int max_jump = 0;
        while(runner <= max_jump) {
            max_jump = max(max_jump, runner + nums[runner]);
            if(max_jump >= nums.size()-1) {
                return true;
            }
            runner++;
        }
        return false;
    }
};