#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int N = prices.size();
    if (N == 1) return 0;
    vector<int> hold(N), sold(N);
    hold[0] = -prices[0];
    sold[0] = 0;
    for (int i = 1; i < N; ++i) {
      hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
      sold[i] = max(sold[i - 1], hold[i - 1] + prices[i] - fee);
    }
    return sold.back();
  }
};
// @lc code=end
