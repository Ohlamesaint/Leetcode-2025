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
 * Space Complexity: O(1) // excluding the space for the output string
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1) return s;

        vector<string> mem(numRows);

    
        int index = 0;
        int direction = 1;
        for(int i=0; i<s.length(); i++) {
            mem[index].push_back(s[i]);
            if(index == 0) {
                direction = 1;
            } else if(index == numRows-1) {
                direction = -1;
            } 
            index+=direction;
        }
        
        string res;

        for(auto& part: mem) {
            res.append(part);
        }
        return res;
    }
};