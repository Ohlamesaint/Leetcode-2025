/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Sam Chen (c) 2025
 * 
 * Time Complexity: O(m+n) where m is the length of t and n is the length of s
 * Space Complexity: O(1)
 * 
 */

#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0) return true;
        if(s.length()>t.length()) return false;
        
        int commonLen = 0;
        for(auto c : t) {
            if(s[commonLen] == c) {
                commonLen++;
                if(commonLen == s.length()) {
                    return true;
                }
            }
        }
        return false;
    }
};