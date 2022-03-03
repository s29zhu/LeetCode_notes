#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int min_price = prices[0], max_profit = 0;
    for (auto& i : prices) {
      max_profit = max(max_profit, i - min_price);
      min_price = min(i, min_price);
    }
    return max_profit;
  }
};
// @lc code=end
