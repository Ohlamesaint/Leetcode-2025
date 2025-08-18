/*
    * @lc app=leetcode id=121 lang=cpp
    *
    * [121] Best Time to Buy and Sell Stock
    *
    * Dynamic Programming
    * 
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int current_max_profit = 0;
        int current_min_price = prices[0];
        for(int i=0; i<prices.size(); i++) {
            if(prices[i]<current_min_price) {
                current_min_price = prices[i];
            } else {
                current_max_profit = max(current_max_profit, prices[i]-current_min_price);
            }
        }
        return current_max_profit;
    }
};