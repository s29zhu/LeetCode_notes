#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int t = accumulate(nums.begin(), nums.end(), 0);
    vector<int> v1(0, 2 * t + 1);
    v1[nums[0] + t] = 1;
    v1[-nums[0] + t] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      vector<int> v2(0, 2 * t + 1);
      for (int j = 0; j < 2 * t + 1; ++j)
        v2[j] = v1[j + nums[i] + t] + v1[j - nums[j] + t];
      v1.swap(v2);
    }
    return v1[target + t];
  }
};
// @lc code=end
