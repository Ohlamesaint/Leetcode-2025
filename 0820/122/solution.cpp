/*
    * @lc app=leetcode id=122 lang=cpp
    *
    * [122] Best Time to Buy and Sell Stock II
    *
    * Greedy
    *
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int current_profit = 0;
        for(int i=1; i<prices.size(); i++) {
            current_profit += max(0, prices[i]-prices[i-1]);
        }
        return current_profit;
    }
};