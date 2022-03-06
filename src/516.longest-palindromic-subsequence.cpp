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
    int N = s.size(), len = 1;
    array<int, 26> counts{0};
    for (auto i : s) len = max(++counts[i - 'a'], len);

    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) dp[i][i] = 1;
    for (int i = 0; i < N - 1; ++i) {
      dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 1;
      if (dp[i][i + 1] > len) len = dp[i][i + 1];
    }

    for (int i = 2; i < N; ++i)
      for (int j = 0; j < N - i; ++j) {
        dp[j][j + i] = max({dp[j + 1][j + i], dp[j][j + i - 1],
                            dp[j + 1][j + i - 1] + (s[j] == s[j + i] ? 2 : 0)});
        if (dp[j][j + i] > len) len = dp[j][j + i];
      }

    print_matrix(dp);
    return len;
  }
};
// @lc code=end

int main() {
  Solution s;
  auto r = s.longestPalindromeSubseq("abcabcabc");

  return 0;
}