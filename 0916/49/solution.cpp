/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-09-16
 * 
 * @copyright Sam Chen (c) 2025
 * 
 * 
 * Time Complexity: O(n * k log k) where n is the number of strings in the input array and k is the maximum length of a string in the input array
 * Space Complexity: O(n * k) where n is the number of strings in the input array and k is the maximum length of a string in the input array
 */

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> resMap;
        for(const auto& str: strs) {
            string strCopy = str;
            sort(strCopy.begin(), strCopy.end());
            resMap[strCopy].push_back(str);
        }

        vector<vector<string>> res;
        res.reserve(resMap.size());

        for(auto& [_, value]: resMap) {
            res.push_back(std::move(value));
        }
        return res;

    }
};