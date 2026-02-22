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
 * 
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;

        while(left<right) {
            int temp = numbers[left] + numbers[right];
            if(temp == target) {
                return {left+1, right+1};
            } else if(temp>target) {
                right--;
            } else {
                left++;
            }
        }
        return {-1, -1};
    }
};