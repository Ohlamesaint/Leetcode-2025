/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief h-Index
 * @version 0.1
 * @date 2025-08-21
 * 
 * @copyright Sam Chen (c) 2025
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        auto dp = vector<int>(citations.size()+1, 0);
        for(auto citation: citations) {
            int index = min(static_cast<int>(dp.size()-1), citation);
            dp[index]++;
        }
        int total = 0;
        for(int i=dp.size()-1; i>=0; i--) {
            total+=dp[i];
            if(total>=i) return i;
        }
        return 0;
    }
};