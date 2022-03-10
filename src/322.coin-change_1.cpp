#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 100000);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i)
      for (int j : coins)
        if (i >= j) dp[i] = min(dp[i], dp[i - j] + 1);
    return dp[amount] == 100000 ? -1 : dp[amount];
  }
};
// @lc code=end
