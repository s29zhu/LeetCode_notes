#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int N = nums.size();
    if (N == 1) return nums[0];
    vector<int> vp(N), vn(N);
    vp[0] = nums[0];
    vn[0] = nums[0];
    int max_p = nums[0];
    
    for (int i = 1; i < N; ++i) {
      if (nums[i] > 0) {
        vp[i] = (vp[i - 1] > 0 ? vp[i - 1] : 1) * nums[i];
        vn[i] = vn[i - 1] * nums[i];
      } else {
        vp[i] = vp[i - 1] * nums[i];
        vn[i] = (vp[i - 1] > 0 ? vp[i - 1] : 1) * nums[i];
      }
      max_p = max(max_p, vp[i]);
    }
    return max_p;
  }
};
// @lc code=end
