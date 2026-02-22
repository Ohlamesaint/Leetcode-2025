/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Sam Chen (c) 2025
 * 
 * Time Complexity: O(n) where n is the length of the string
 * Space Complexity: O(1) 
 */

#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1;
        const int gap = 'a'-'A';
        while(left < right) {
            while(left < right && !isalnum(s[left])) {
                left++;
            }
            while(left < right && !isalnum(s[right])) {
                right--;
            }
            if(tolower(s[left])!=tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};