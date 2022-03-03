#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> rst{{1}};
    rst.reserve(numRows);
    for (int i = 1; i < numRows; ++i) {
      rst.emplace_back(i + 1, 1);
      for (int j = 1; j < i; ++j) rst[i][j] = rst[i - 1][j - 1] + rst[i - 1][j];
    }
    return rst;
  }
};
// @lc code=end
