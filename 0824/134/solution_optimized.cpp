/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-08-24
 * 
 * @copyright Copyright (c) 2025
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */


// two important properties:
// 1. if the total gas is less than the total cost, there is no solution
// 2. if starting from A to B, the gas is not enough, any station between A and B cannot be the start point

#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int current_gas = 0;
        int start_index = 0;

        for(int i=0; i<gas.size(); i++) {
            total_gas+=gas[i]-cost[i];
            current_gas+=gas[i]-cost[i];
            if(current_gas<0) {
                start_index = i+1;
                current_gas = 0;
            }
        }
        return total_gas < 0 ? -1 : start_index;
    }
};