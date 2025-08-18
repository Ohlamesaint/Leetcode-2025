/*
    * @lc app=leetcode.cn id=169 lang=cpp
    *
    * [169] Majority Element
    * 
    * Boyer-Moore Voting Algorithm
    *
*/

#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int current_majority = nums[0];
       int current_majority_index = 0;
       for(int i=1; i<nums.size(); i++) {
        if(nums[i]==current_majority) {
            current_majority_index++;
        } else {
            if(current_majority_index == 0) {
                current_majority = nums[i];
            } else {
                current_majority_index--;
            }
        }
       } 
       return current_majority;
    }
};