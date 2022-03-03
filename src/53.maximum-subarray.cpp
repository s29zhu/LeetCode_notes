#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int N = nums.size();
    if (N == 1) return nums[0];
    int p1 = 0, p2 = N - 1, s1 = nums[p1], s2 = nums[p2];
    int i = p1 + 1, j = p2 - 1;
    while (i < j) {
      if (s1 < s2) {
        if (s1 + nums[i] < 0) {
          p1 = ++i;
          s1 = 0;
        } else {
          s1 += nums[i++];
        }

      } else {
        if (s2 + nums[j] < 0) {
          p2 = --j;
          s2 = 0;
        } else {
          s2 += nums[j--];
        }
      }
    }
    return s1 + s2;
  }
};
// @lc code=end
