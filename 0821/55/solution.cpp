/**
 * @file solution.cpp
 * @author Sam Chen 
 * @brief Jump Game
 * @version 0.1
 * @date 2025-08-21
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(i>max_jump) return false;
            max_jump = max(max_jump, i+nums[i]);
        }
        return true;
        
    }
};