#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
 public:
  int rob(vector<int>& nums) {
    int N = nums.size();
    if (N == 1) return nums[0];
    array<int, 2> a1{nums[0], nums[0]}, a2{0, nums[1]};
    for (int i = 2; i < N; ++i) {
      a1[i % 2] = max(a1[i % 2] + nums[i], a1[(i + 1) % 2]);
      a2[i % 2] = max(a2[i % 2] + nums[i], a2[(i + 1) % 2]);
    }
    return max(a1[N % 2], a2[(N - 1) % 2]);
  }
};
// @lc code=end
