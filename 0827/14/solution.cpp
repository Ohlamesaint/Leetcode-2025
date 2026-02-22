/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-08-27
 * 
 * 
 * @copyright Copyright (c) 2025
 * 
 *  * 14. Longest Common Prefix
 * 
 * Time Complexity: O(n*m) where n is the number of strings and m is the length of the shortest string
 * Space Complexity: O(1)
 * 
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int maxCommon = strs[0].length();
        for(int i=1; i<strs.size(); i++){
            for(int j=0; j<maxCommon; j++) {
                if(strs[i][j] != strs[0][j]) {
                    maxCommon = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, maxCommon);
    }
};