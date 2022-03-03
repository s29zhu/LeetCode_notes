#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=1314 lang=cpp
 *
 * [1314] Matrix Block Sum
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int M = mat.size(), N = mat[0].size();
    for (int i = 0; i < M; ++i)
      for (int j = 1; j < N; ++j) mat[i][j] += mat[i][j - 1];
    for (int j = 0; j < N; ++j)
      for (int i = 1; i < M; ++i) mat[i][j] += mat[i - 1][j];
    auto v = [&](int i, int j) {
      return i < 0 || j < 0 ? 0 : mat[min(i, M - 1)][min(j, N - 1)];
    };
    vector<vector<int>> rst(M, vector<int>(N));
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        rst[i][j] = v(i + k, j + k) - v(i + k, j - k - 1) +
                    v(i - k - 1, j - k - 1) - v(i - k - 1, j + k);
    return rst;
  }
};
// @lc code=end

int main() {
  vector<vector<int>> mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution s;
  auto rst = s.matrixBlockSum(mat, 1);
  return 0;
}