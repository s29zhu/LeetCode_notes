#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
 public:
  int tribonacci(int n) {
    array<int, 3> a{0, 1, 1};
    for (int i = 3; i <= n; ++i)
      a[i % 3] = a[(i - 1) % 3] + a[(i - 2) % 3] + a[i % 3];
    return a[n % 3];
  }
};
// @lc code=end
