#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1, m = 0;
    while (i < j) {
      m = max(m, (j - i) * min(height[i], height[j]));
      if (height[i] < height[j])
        ++i;
      else
        --j;
    }
    return m;
  }
};
// @lc code=end
