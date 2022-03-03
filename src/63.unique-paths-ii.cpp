#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int M = obstacleGrid.size(), N = obstacleGrid[0].size();
    vector<vector<int>> dp(M, vector<int>(N));
    if (obstacleGrid[0][0] == 1) return 0;
    dp[0][0] = 1;
    for (int i = 1; i < N; ++i)
      dp[0][i] = obstacleGrid[0][i] == 1 ? 0 : dp[0][i - 1];
    for (int i = 1; i < M; ++i)
      dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];

    for (int i = 1; i < M; ++i)
      for (int j = 1; j < N; ++j)
        dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
    return dp[M - 1][N - 1];
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> a{{1, 0}};
  int r = s.uniquePathsWithObstacles(a);
  return 0;
}