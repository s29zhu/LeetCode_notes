#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=1567 lang=cpp
 *
 * [1567] Maximum Length of Subarray With Positive Product
 */

// @lc code=start
class Solution {
 public:
  int getMaxLen(const vector<int>& nums) {
    int N = nums.size();
    if (N == 1) return nums[0] > 0;
    vector<int> vp(N), vn(N);
    vp[0] = nums[0] > 0;
    vn[0] = nums[0] < 0;
    int m = 0;

    for (int i = 1; i < N; ++i) {
      if (nums[i] > 0) {
        vp[i] = vp[i - 1] + 1;
        vn[i] = vn[i - 1] == 0 ? 0 : vn[i - 1] + 1;
      } else if (nums[i] < 0) {
        vp[i] = vn[i - 1] == 0 ? 0 : vn[i - 1] + 1;
        vn[i] = vp[i - 1] + 1;
      } else {
        vp[i] = 0;
        vn[i] = 0;
      }
      m = max(m, vp[i]);
    }

    return m;
  }
};
// @lc code=end
