#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */

// @lc code=start
class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i : coins)
      for (int j = 0; i + j <= amount; ++j) dp[i + j] += dp[j];
    return dp[amount];
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> coins{1, 2, 5};
  auto r = s.change(5, coins);
  cout << r << endl;
  return 0;
}