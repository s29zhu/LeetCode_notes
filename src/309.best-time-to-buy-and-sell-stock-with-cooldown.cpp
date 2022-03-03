#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int N = prices.size();
    vector<int> v1(N + 1, 0), v2(N + 1, 0);
    for (int i = N - 2; i >= 0; --i) {
      v1[i] = max(v1[i + 1] + prices[i + 1] - prices[i], max(v1[i + 2], v2[i + 2]));
      v2[i] = max(v1[i + 1], v2[i + 1]);
    }
    return max(v1[0], v2[0]);
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> a{1,2,3,0,2};
  int r = s.maxProfit(a);
  cout << r << endl;
  return 0;
}