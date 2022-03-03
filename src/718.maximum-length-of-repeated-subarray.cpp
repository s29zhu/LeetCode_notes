#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution {
 public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int M = nums1.size(), N = nums2.size();
    vector<vector<int>> dp(M, vector<int>(N, 0));
    for (int i = 0; i < M; ++i) dp[i][0] = nums1[i] == nums2[0];
    for (int i = 0; i < N; ++i) dp[0][i] = nums1[0] == nums2[i];

    for (int i = 1; i < M; ++i)
      for (int j = 1; j < N; ++j)
        dp[i][j] = nums1[i] == nums2[j] ? dp[i - 1][j - 1] + 1 : 0;

    int r = 0;
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        if (dp[i][j] > r) r = dp[i][j];
    return r;
  }
};
// @lc code=end
