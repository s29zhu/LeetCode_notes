#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    array<int, 2> a{cost[0], cost[1]};
    for (int i = 2; i < cost.size(); ++i)
      a[i % 2] = min(a[i % 2], a[(i - 1) % 2]) + cost[i];
    return min(a[0], a[1]);
  }
};
// @lc code=end
