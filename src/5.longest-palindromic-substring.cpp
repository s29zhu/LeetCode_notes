#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
 public:
  string longestPalindrome(string s) {
    int N = s.size(), len = 1, start = 0;
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) dp[i][i] = 1;
    for (int i = 0; i < N - 1; ++i) {
      dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 0;
      if (dp[i][i + 1] > len) {
        len = dp[i][i + 1];
        start = i;
      }
    }
    for (int i = 2; i < N; ++i)
      for (int j = 0; j < N - i; ++j) {
        dp[j][j + i] = s[j] == s[j + i] && dp[j + 1][j + i - 1]
                           ? dp[j + 1][j + i - 1] + 2
                           : 0;
        if (dp[j][j + i] > len) {
          len = dp[j][j + i];
          start = j;
        }
      }
    return {s.begin() + start, s.begin() + start + len};
  }
};
// @lc code=end

int main() {
  Solution ss;
  string s("cbba");
  auto r = ss.longestPalindrome(s);

  return 0;
}