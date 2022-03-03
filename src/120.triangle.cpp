#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    for (int i = 1; i < triangle.size(); ++i) {
      triangle[i][0] += triangle[i - 1][0];
      for (int j = 1; j < i; ++j)
        triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
      triangle[i][i] += triangle[i - 1][i - 1];
    }
    return *min_element(triangle.back().begin(), triangle.back().end());
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  int r = s.minimumTotal(triangle);
  return 0;
}