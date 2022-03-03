#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int N = nums.size();
    if (N == 1) return nums[0];

    int m1 = nums[0], m2 = nums[1];
    vector<int> v(N, m1);
    for (int i = 1; i < N; ++i) {
      v[i] = nums[i] + (v[i - 1] < 0 ? 0 : v[i - 1]);
      m1 = max(m1, v[i]);
    }
    v[1] = m2;
    for (int i = 2; i < N - 1; ++i) {
      v[i] = nums[i] + (v[i - 1] > 0 ? 0 : v[i - 1]);
      m2 = min(m2, v[i]);
    }
    int s = std::accumulate(nums.begin(), nums.end(), 0);
    return max(m1, s - m2);
  }
};
// @lc code=end
