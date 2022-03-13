#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    int N = prices.size();
    if (N < 2) return 0;
    int m = numeric_limits<int>::min() / 2;
    vector<vector<int>> h(N, vector<int>(k, m)), s(N, vector<int>(k, m));
    h[0][0] = -prices[0];
    for (int i = 1; i < N; ++i) {
      h[i][0] = max(h[i - 1][0], -prices[i]);
      s[i][0] = max(s[i - 1][0], max(h[i - 1][0], h[i][0]) + prices[i]);
      for (int j = 1; j < k; ++j) {
        h[i][j] = max(h[i - 1][j], s[i - 1][j - 1] - prices[i]);
        s[i][j] = max(s[i - 1][j], max(h[i - 1][j], h[i][j]) + prices[i]);
      }
    }
    return *max_element(s.back().begin(), s.back().end());
  }
};
// @lc code=end

int main() {
  vector<int> prices{2, 1};
  Solution s;
  cout << s.maxProfit(1, prices) << endl;
  return 0;
}
