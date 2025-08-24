/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-08-24
 * 
 * @copyright Copyright (c) 2025
 * 
 * Time Complexity: O(n) amortized
 * Space Complexity: O(1)
 */



#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int route_length = gas.size();
        for(int i=0; i<route_length; i++) {
            int isFailed = false;
            int current_gas = 0;
            for(int j=i; j<i+route_length; j++) {
                int index = j%route_length;
                current_gas += gas[index]-cost[index];
                if(current_gas < 0) {
                    isFailed = true;
                    i=j;
                    break;
                }
            }
            if(!isFailed) return i;
        }
        return -1;
    }
};