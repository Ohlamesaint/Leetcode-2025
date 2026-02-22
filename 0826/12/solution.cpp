/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-08-26
 * 
 * @copyright Copyright (c) 2025
 * 
 * Time Complexity: O(1) 
 * Space Complexity: O(1)
 */

#include <vector>
#include <string>
#include <utility>

using namespace std;

class Solution {

    vector<pair<int, string>> value2Symbol = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"}, 
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };

public:
    string intToRoman(int num) {
        string res;
        for(auto &pair : value2Symbol) {
            while(num>=pair.first) {
                res.append(pair.second);
                num-=pair.first;
            }
           
        }
        return res;
    }
};