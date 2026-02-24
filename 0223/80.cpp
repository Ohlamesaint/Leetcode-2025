#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicatesOptimized(vector<int>& nums) {
        if(nums.size() <= 2) {
            return nums.size();
        }
        int last_insert_pos = 1;
        for(int i=2; i<nums.size(); i++) {
            if(nums[i]!=nums[last_insert_pos-1]) {
                last_insert_pos++;
                nums[last_insert_pos] = nums[i];
            }
        }
        return last_insert_pos+1;
    }

    int removeDuplicatesRefined(vector<int>& nums) {
        if(nums.size() <= 2) {
            return nums.size();
        }
        int next_insert_pos = 2;
        int prev = nums[1], prev_prev = nums[0];
        for(int i=2; i<nums.size(); i++) {
            if(nums[i]!=prev_prev) {
                nums[next_insert_pos] = nums[i];
                next_insert_pos++;
            }
            prev_prev = prev;
            prev = nums[i];
        }
        return next_insert_pos;
    }

    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        bool duplicated = false;
        int last_insert_pos = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]!=nums[last_insert_pos]) {
                last_insert_pos++;
                nums[last_insert_pos] = nums[i];
                duplicated = false;
            } else {
                if(!duplicated) {
                    last_insert_pos++;
                    nums[last_insert_pos] = nums[i];
                    duplicated = true;
                }
            }
        }
        return last_insert_pos+1;
    }
};