#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> rst;
    permute(nums, 0, rst);
    return rst;
  }
  void permute(vector<int>& nums, size_t n, vector<vector<int>>& rst) {
    if (n == nums.size() - 1)
      rst.push_back(nums);
    else {
      set<int> used{nums[n]};
      permute(nums, n + 1, rst);
      for (size_t i = n + 1; i < nums.size(); ++i)
        if (used.find(nums[i]) == used.end()) {
          used.insert(nums[i]);
          swap(nums[i], nums[n]);
          permute(nums, n + 1, rst);
          swap(nums[i], nums[n]);
        }
    }
  }
};
// @lc code=end
