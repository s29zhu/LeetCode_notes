#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int rst = 0, N = nums.size();
    if (N < 3) return 0;
    for (int i = 2, n = 0; i < N; ++i)
      if (nums[i - 1] * 2 == nums[i - 2] + nums[i]) {
        rst += ++n;
      } else {
        n = 0;
      }
    return rst;
  }
};
// @lc code=end
