#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int N = matrix.size();
    for (int i = 1; i < N; ++i) {
      matrix[i][0] += min(matrix[i - 1][0], matrix[i - 1][1]);
      for (int j = 1; j < N - 1; ++j)
        matrix[i][j] +=
            min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i - 1][j + 1]});
      matrix[i][N - 1] += min(matrix[i - 1][N - 2], matrix[i - 1][N - 1]);
    }
    return *min_element(matrix.back().begin(), matrix.back().end());
  }
};
// @lc code=end
