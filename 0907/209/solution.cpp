/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Sam Chen (c) 2025
 * 
 * Time Complexity: O(n) where n is the length of the input array
 * Space Complexity: O(1)
 * 
 */

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int currentSum = 0, res = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            currentSum += nums[right];
            while(currentSum>=target) {
                res = min(res, right-left+1);
                currentSum-=nums[left];
                left++;
            }
            right++;
        }
        return res == INT_MAX ? 0 : res;
    }
};