#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
 public:
  double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n == -1) return 1 / x;
    double s = myPow(x, n / 2), r = n % 2 ? (n > 0 ? x : 1 / x) : 1;
    return s * s * r;
  }
};
// @lc code=end
