/**
 * @file solution_optimized.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.2
 * @date 2025-08-21
 * 
 * @copyright Copyright (c) 2025
 * 
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {

        int current_min_jump = 0;
        int current_max_index = 0;
        int next_max_index = nums[0];

        for(int i=0; i<nums.size(); i++) {
            if(current_max_index<i) {
                current_min_jump++;
                current_max_index = next_max_index;
            }
            next_max_index = max(next_max_index, nums[i]+i);
        }

        return current_min_jump;
        
    }
};