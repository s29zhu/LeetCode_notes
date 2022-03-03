#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> rst(rowIndex + 1, 1);
    for (int i = 0; i < rowIndex; ++i)
      for (int j = i; j > 0; --j) rst[j] += rst[j - 1];
    return rst;
  }
};
// @lc code=end
