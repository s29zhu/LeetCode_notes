#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int M = text1.size(), N = text2.size();
    vector<vector<int>> dp(M, vector<int>(N, 0));
    dp[0][0] = text1[0] == text2[0];
    for (int i = 1; i < M; ++i) dp[i][0] = dp[i - 1][0] || text1[i] == text2[0];
    for (int i = 1; i < N; ++i) dp[0][i] = dp[0][i - 1] || text1[0] == text2[i];
    for (int i = 1; i < M; ++i)
      for (int j = 1; j < N; ++j)
        if (text1[i] == text2[j])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    return dp.back().back();
  }
};
// @lc code=end
