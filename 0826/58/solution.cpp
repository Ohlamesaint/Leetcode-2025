/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-08-27
 * 
 * @copyright Copyright (c) 2025
 * 
 * Time Complexity: O(n) // length of the string
 * Space Complexity: O(1)
 */

#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int start = -1;
        int end = -1;
        for(int i=s.length()-1; i>=0; i--) {
            if(s[i]!=' ' && start==-1) {
                start = i;
            } else if(s[i]==' ' && start!=-1) {
                end = i;
                break;
            }
        }
        return start-end;
    }
};