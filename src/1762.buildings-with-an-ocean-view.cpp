#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=1762 lang=cpp
 *
 * [1762] Buildings With an Ocean View
 */

// @lc code=start
class Solution {
 public:
  vector<int> findBuildings(vector<int>& heights) {
    int m = 0;
    vector<int> rst;
    for (int i = heights.size(); i >= 0; ++i)
      if (heights[i] > m) {
        rst.push_back(i);
        m = heights[i];
      }
    return {rst.rbegin(), rst.rend()};
  }
};
// @lc code=end