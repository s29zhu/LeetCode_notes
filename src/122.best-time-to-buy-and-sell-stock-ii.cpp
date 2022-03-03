#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int pv = 0, profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] < prices[i - 1]) {
        if (prices[i - 1] - prices[pv] > 0)
          profit += prices[i - 1] - prices[pv];
        pv = i;
      }
    }
    if (prices.back() - prices[pv] > 0) profit += prices.back() - prices[pv];

    return profit;
  }
};
// @lc code=end
