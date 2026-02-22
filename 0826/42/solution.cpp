/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-08-26
 * 
 * @copyright Copyright (c) 2025
 * 
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

 /* Two pointers
  * Keep track of the maximum height from both ends
  * Move the pointer with the smaller maximum height
  * Calculate the trapped water at each step
  * 
  * The key insight is that the amount of water that can be trapped at a given position is determined by the shorter of the two maximum heights (from the left and right).
  * By always moving the pointer with the smaller maximum height, we ensure that we are making progress towards finding all trapped water while maintaining the correct boundaries.
  * 
  * This approach ensures that each element is processed only once, leading to an O(n) time complexity.
  * The space complexity is O(1) since we are using only a constant amount of extra space.
  */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftLocalMax = height.front();
        int rightLocalMax = height.back();
        int totalTrappingWater = 0;

        while(left<right) {
            if(leftLocalMax < rightLocalMax) {
                left++;
                leftLocalMax = max(height[left], leftLocalMax);
                totalTrappingWater += leftLocalMax - height[left];
            } else {
                right--;
                rightLocalMax = max(height[right], rightLocalMax);
                totalTrappingWater += rightLocalMax-height[right];
            }
        }
        return totalTrappingWater;
    }
};