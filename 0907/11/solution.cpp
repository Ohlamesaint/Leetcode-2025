/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Copyright (c) 2025
 * 
 * Time Complexity: O(n) where n is the length of the input array
 * Space Complexity: O(1)
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maxContain = 0;
        while(left < right) {
            maxContain = max(maxContain, (right-left)*min(height[left], height[right]));
            if(height[left] < height[right]) left++;
            else right--;
        }
        return maxContain;
    }
};