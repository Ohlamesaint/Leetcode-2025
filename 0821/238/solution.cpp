/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-08-21
 * 
 * @copyright Sam Chen (c) 2025
 * 
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n) (O(1) if not considering the output array)
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto result = vector<int>(nums.size(), 1);
        int left_product = 1;
        int right_product = 1;

        for(int i=0; i<nums.size(); i++) {
            result[i] *= left_product;
            left_product *= nums[i];
            result[nums.size()-i-1] *= right_product;
            right_product *= nums[nums.size()-i-1];
        }
        return result;
    }
};