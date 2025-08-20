/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief Jump Game II
 * @version 0.1
 * @date 2025-08-21
 * 
 * @copyright SamChen (c) 2025
 * 
 * 
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        auto dp = vector<int>(nums.size(), INT_MAX);
        dp[0] = 0;
        for(int i=0; i<nums.size(); i++) {
            for(int j=1; j<=nums[i] && (i+j)<nums.size(); j++) {
                dp[i+j] = min(dp[i+j], dp[i]+1);
                if((i+j)==nums.size()-1) return dp[i+j];
            }
        }
        return dp.back();
    }
};