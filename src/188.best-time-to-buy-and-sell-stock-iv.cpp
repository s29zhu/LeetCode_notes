#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    int N = prices.size();
    if (N == 1) return 0;
    int m = numeric_limits<int>::min() / 2;
    vector<vector<int>> h(k, vector<int>(N, m)), s(k, vector<int>(N, m));
    h[0][0] = -prices[0];
    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < k; ++j) {
        
      }
    }
  }
};
// @lc code=end
