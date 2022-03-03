#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int M = grid.size(), N = grid[0].size();
    vector<vector<int>> dp(M, vector<int>(N, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < N; ++i) dp[0][i] = grid[0][i] + dp[0][i - 1];
    for (int i = 1; i < M; ++i) dp[i][0] = grid[i][0] + dp[i - 1][0];

    for (int i = 1; i < M; ++i)
      for (int j = 1; j < N; ++j)
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];

    return dp[M - 1][N - 1];
  }
};
// @lc code=end
