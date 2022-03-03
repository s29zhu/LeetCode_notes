#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int M = matrix.size(), N = matrix[0].size(), r = 0;
    vector<vector<int>> v(M, vector<int>(N, 0));
    for (int i = 0; i < M; ++i) v[i][0] = matrix[i][0] == '1';
    for (int i = 0; i < N; ++i) v[0][i] = matrix[0][i] == '1';

    for (int i = 1; i < M; ++i)
      for (int j = 1; j < N; ++j)
        if (matrix[i][j] == '1')
          v[i][j] = min({v[i - 1][j - 1], v[i - 1][j], v[i][j - 1]}) + 1;

    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        if (v[i][j] > r) r = v[i][j];

    return r * r;
  }
};
// @lc code=end
