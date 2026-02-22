/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Sam Chen (c) 2025
 * 
 * Time Complexity: O(n) where n is the length of the input string
 * Space Complexity: O(1)
 * 
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mem(128, 0);

        int left = 0;
        int maxLength = 0;
        for(int i=0; i<s.length(); i++) {
            mem[s[i]]++;
            while(mem[s[i]]>1) {
                mem[s[left]]--;
                left++;
            }
            maxLength = max(maxLength, i-left+1);
        }
        return maxLength;
    }
};