#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    vector<int> dp(amount + 1, 100000);
    dp[0] = 0;
    for (int i = 0; i <= amount; ++i) {
      if (dp[i] != 100000)
        for (auto j : coins)
          if (j <= amount && i + j <= amount)
            dp[i + j] = min(dp[i + j], dp[i] + 1);
    }
    return dp[amount] == 100000 ? -1 : dp[amount];
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> coins{456, 117, 5};
  auto r = s.coinChange(coins, 1001);
  cout << r << endl;
  return 0;
}