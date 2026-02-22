/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Sam Chen (c) 2025
 * 
 * Time Complexity: O(n^2) where n is the length of the input array
 * Space Complexity: O(1) // excluding the space for the output
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return a < b;
        });

        vector<vector<int>> res({});

        for(int i=0; i<nums.size()-2; i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1, k = nums.size()-1;
            while(j<k) {
                int temp = nums[i] + nums[j] + nums[k];
                if(temp == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    while(j<k && nums[j]==nums[j-1]) ++j;
                    --k;
                    while(j<k && nums[k]==nums[k+1]) --k;
                } else if(temp > 0) {
                    k--;
                    while(j<k && nums[k]==nums[k+1]) --k;
                } else {
                    j++;
                    while(j<k && nums[j]==nums[j-1]) ++j;
                }
            }
        }
        return res;
    }
};