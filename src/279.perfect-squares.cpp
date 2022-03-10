#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
 public:
  int numSquares(int n) {
    array<int, 100> ns;
    for (int i = 0; i < 100; ++i) ns[i] = (i + 1) * (i + 1);

    vector<int> dp(n + 1, 100000);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
      for (auto j : ns)
        if (i >= j) dp[i] = min(dp[i], dp[i - j] + 1);
    return dp[n];
  }
};
// @lc code=end
