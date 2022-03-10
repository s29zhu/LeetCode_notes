#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i)
      for (int j = 1; j <= i; ++j) 
        dp[i] = max({dp[i], dp[i - j] * j, (i - j + 1) * j});
    return dp.back();
  }
};
// @lc code=end

int main() {
  Solution s;
  cout << s.integerBreak(4) << endl;
  return 0;
}