#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int N = prices.size();
    if (N == 1) return 0;
    int m = numeric_limits<int>::min() / 2;
    vector<int> h1(N, m), h2(N, m), s1(N, m), s2(N, m);
    h1[0] = -prices[0];
    for (int i = 1; i < N; ++i) {
      h1[i] = max(h1[i - 1], -prices[i]);
      s1[i] = max(s1[i - 1], h1[i - 1] + prices[i]);
      h2[i] = max(h2[i - 1], s1[i - 1] - prices[i]);
      s2[i] = max(s2[i - 1], h2[i - 1] + prices[i]);
    }
    return max({s1.back(), s2.back(), 0});
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> a{1, 2, 3, 4, 5};
  int p = s.maxProfit(a);
  cout << p << endl;
  return 0;
}