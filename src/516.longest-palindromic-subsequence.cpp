#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    int N = s.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) dp[i][i] = 1;

    for (int i = 1; i < N; ++i)
      for (int j = 0; j < N - i; ++j)
        dp[j][j + i] = s[j] == s[j + i]
                           ? dp[j + 1][j + i - 1] + 2
                           : max(dp[j + 1][j + i], dp[j][j + i - 1]);

    return dp.front().back();
  }
};
// @lc code=end

int main() {
  Solution s;
  auto r = s.longestPalindromeSubseq("abcabcabc");

  return 0;
}