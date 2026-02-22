/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-08-26
 * 
 * @copyright Copyright (c) 2025
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 */

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);

        for(int i=1; i<ratings.size(); i++) {
            if(ratings[i]>ratings[i-1]) {
                candies[i] = max(candies[i], candies[i-1]+1);
            }
        }

        for(int i=ratings.size()-2; i>=0; i--) {
            if(ratings[i]>ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};