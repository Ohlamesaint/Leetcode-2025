#include <vector>
#include <algorithm>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int duplicate_num = 2;
        for(int i=2; i<nums.size(); i++) {
            if(nums[i]!=nums[duplicate_num-2]) {
                nums[duplicate_num] = nums[i];
                duplicate_num++;
            }
        }
        return std::min(static_cast<int>(nums.size()), duplicate_num);
    }
};