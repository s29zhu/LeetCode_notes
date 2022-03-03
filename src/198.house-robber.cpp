#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
 public:
  int rob(vector<int>& nums) {
    array<int, 2> a{0, 0};
    int N = nums.size();
    for (int i = 0; i < N; ++i)
      a[i % 2] = max(a[i % 2] + nums[i], a[(i + 1) % 2]);
    return a[(N - 1) % 2];
  }
};
// @lc code=end
