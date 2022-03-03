#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int N = nums.size();
    vector<vector<int>> rst(1 << N);
    for (int i = 0; i < nums.size(); ++i) {
      int n = 1 << (N - i - 1);
      for (int j = 1; j < 2 << i; j += 2)
        for (int k = 0; k < n; ++k) rst[j * n + k].push_back(nums[i]);
    }
    return rst;
  }
};
// @lc code=end
