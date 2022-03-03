#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
 public:
  int climbStairs(int n) {
    array<int, 2> a{1, 2};
    for (int i = 3; i <= n; ++i) a[(i - 1) % 2] = a[(i - 1) % 2] + a[i % 2];
    return a[(n - 1) % 2];
  }
};
// @lc code=end
