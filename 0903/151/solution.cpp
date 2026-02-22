/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-09-03
 * 
 * @copyright Copyright (c) 2025
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 */

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        auto first = s.find_first_not_of(' ');
        auto last = s.find_last_not_of(' ')+1;
        int left = first, right = first;
        int index = 0;
        while(right != last) {
            if(s[right] == ' ' && s[left] != ' ') {
                reverse(s.begin()+left, s.begin()+right);
                while(left != right) {
                    s[index] = s[left];
                    index++;
                    left++;
                }
                s[index] = ' ';
                index++;
            } else if(s[left] == ' ') {
                left++;
            }
            right++;
        }

        if(left != right) {
            reverse(s.begin()+left, s.begin()+right);
            while(left != right) {
                s[index] = s[left];
                index++;
                left++;
            }
        }
        return s.substr(0, index);
    }
};