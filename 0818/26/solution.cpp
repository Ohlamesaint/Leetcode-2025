#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int distinct_num = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != nums[i-1]) {
                nums[distinct_num] = nums[i];
                distinct_num++;
            }
        }
        return distinct_num;
    }
};