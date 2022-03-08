#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
 public:
  int minDistance(string A, string B) {
    int M = A.size(), N = B.size();
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    for (int i = 1; i < M + 1; ++i) dp[i][0] = i;
    for (int i = 1; i < N + 1; ++i) dp[0][i] = i;
    for (int i = 1; i < M + 1; ++i)
      for (int j = 1; j < N + 1; ++j)
        dp[i][j] =
            A[i - 1] == B[j - 1]
                ? dp[i - 1][j - 1]
                : 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
    return dp.back().back();
  }
};
// @lc code=end
