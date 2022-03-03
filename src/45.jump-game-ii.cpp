#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
 public:
  int jump(vector<int>& nums) {
    int N = (int)nums.size(), n = 1, prev_max = 0, curr_max = nums[0];
    if (N == 1) return 0;
    for (int i = 0; i < N; ++i) {
      if (i > prev_max) {
        prev_max = curr_max;
        ++n;
      }
      int j = i + nums[i];
      if (j >= N - 1) return n;
      if (j > curr_max) curr_max = j;
    }
    return -1;
  }
};
// @lc code=end
