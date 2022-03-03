#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> rst;
    permute(nums, 0, rst);
    return rst;
  }
  void permute(vector<int>& nums, size_t n, vector<vector<int>>& rst) {
    if (n == nums.size() - 1)
      rst.push_back(nums);
    else {
      permute(nums, n + 1, rst);
      for (int i = n + 1; i < nums.size(); ++i) {
        swap(nums[i], nums[n]);
        permute(nums, n + 1, rst);
        swap(nums[i], nums[n]);
      }
    }
  }
};
// @lc code=end
