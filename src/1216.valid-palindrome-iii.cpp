#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=1216 lang=cpp
 *
 * [1216] Valid Palindrome III
 */

// @lc code=start
class Solution {
 public:
  bool isValidPalindrome(string s, int k) {
    int N = s.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) dp[i][i] = 1;
    for (int i = 1; i < N; ++i)
      for (int j = 0; j < N - i; ++j) {
        dp[j][i + j] = s[j] == s[i + j]
                           ? dp[j + 1][i + j - 1] + 2
                           : max(dp[j + 1][i + j], dp[j][i + j - 1]);
        if (dp[j][i] >= N - k) return true;
      }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  cout << boolalpha << s.isValidPalindrome("baacacaa", 1) << endl;
  return 0;
}