#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
/* class Solution {
 public:
  bool canJump(vector<int>& nums) {
    for (int i = 0, max_i = nums[0], N = nums.size(); i < N && i <= max_i; ++i)
      if ((max_i = max(max_i, nums[i] + i)) >= N - 1) return true;
    return false;
  }
}; */

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int lp = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (i + nums[i] >= lp) lp = i;
    }
    return lp == 0;
  }
};
// @lc code=end
