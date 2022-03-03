#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
  vector<vector<int>>& mat;
  int M, N;

 public:
  NumMatrix(vector<vector<int>>& matrix) : mat(matrix) {
    M = mat.size(), N = mat[0].size();
    for (int i = 0; i < M; ++i)
      for (int j = 1; j < N; ++j) mat[i][j] += mat[i][j - 1];
    for (int j = 0; j < N; ++j)
      for (int i = 1; i < M; ++i) mat[i][j] += mat[i - 1][j];
  }

  int v(int i, int j) {
    return i < 0 || j < 0 ? 0 : mat[min(i, M - 1)][min(j, N - 1)];
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return v(row2, col2) - v(row1 - 1, col2) + v(row1 - 1, col1 - 1) -
           v(row2, col1 - 1);
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
