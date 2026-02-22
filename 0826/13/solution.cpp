/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-08-26
 * 
 * @copyright Copyright (c) 2025
 * 
 * Time Complexity: O(n) // length of the string
 * Space Complexity: O(1)
 * 
 */

#include <unordered_map>
#include <string>

using namespace std;

class Solution {

    unordered_map<char, int> symbol2Value = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

public:
    int romanToInt(string s) {
        int value = 0;
        for(int i=0; i<s.length(); i++) {
            if(i+1<s.length() && symbol2Value[s[i+1]]>symbol2Value[s[i]]) {
                value += symbol2Value[s[i+1]]-symbol2Value[s[i]];
                i++;
            } else {
                value += symbol2Value[s[i]];
            }
        }
        return value;
    }
};