#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start
class Solution {
  int N;
  using Matrix = vector<vector<int>>;
  Matrix islands;

 public:
  int largestIsland(vector<vector<int>>& grid) {
    N = grid.size();

    if (grid[0][0] == 0)
      grid[0][0] = -1;
    else
      new_island(0, 0, grid);

    for (int i = 1; i < N; ++i) {
      if (grid[0][i] == 0)
        grid[0][i] = -1;
      else if (grid[0][i - 1] < 0)
        new_island(0, i, grid);
      else
        enlarge_island(grid[0][i - 1], 0, i, grid);
    }
    for (int i = 1; i < N; ++i) {
      if (grid[i][0] == 0)
        grid[i][0] = -1;
      else if (grid[i - 1][0] < 0)
        new_island(i, 0, grid);
      else
        enlarge_island(grid[i - 1][0], i, 0, grid);
    }

    for (int i = 1; i < N; ++i)
      for (int j = 1; j < N; ++j) {
        if (grid[i][j] == 0) {
          grid[i][j] = -1;
        } else if (grid[i][j - 1] >= 0) {
          enlarge_island(grid[i][j - 1], i, j, grid);
          if (grid[i - 1][j] >= 0 && grid[i][j - 1] != grid[i - 1][j])
            merge_islands(grid[i][j - 1], grid[i - 1][j], grid);
        } else if (grid[i - 1][j] >= 0) {
          enlarge_island(grid[i - 1][j], i, j, grid);
        } else {
          new_island(i, j, grid);
        }
      }

    int rst = 0;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        rst = max(rst, grid[i][j] < 0 ? largest_island(i, j, grid)
                                      : (int)islands[grid[i][j]].size());
    return rst;
  }

  void new_island(int i, int j, Matrix& grid) {
    islands.push_back({N * i + j});
    grid[i][j] = islands.size() - 1;
  }
  void enlarge_island(int k, int i, int j, Matrix& grid) {
    islands[k].push_back(N * i + j);
    grid[i][j] = k;
  }
  void merge_islands(int k1, int k2, Matrix& grid) {
    if (islands[k1].size() < islands[k2].size()) swap(k1, k2);
    islands[k1].insert(islands[k1].end(), islands[k2].begin(),
                       islands[k2].end());
    for (auto& i : islands[k2]) grid[i / N][i % N] = k1;
    islands[k2].clear();
  }
  int largest_island(int i, int j, Matrix& grid) {
    unordered_set<int> s;
    if (i > 0 && grid[i - 1][j] >= 0) s.insert(grid[i - 1][j]);
    if (i < N - 1 && grid[i + 1][j] >= 0) s.insert(grid[i + 1][j]);
    if (j > 0 && grid[i][j - 1] >= 0) s.insert(grid[i][j - 1]);
    if (j < N - 1 && grid[i][j + 1] >= 0) s.insert(grid[i][j + 1]);

    int rst = 1;
    for (auto i : s) rst += islands[i].size();
    return rst;
  }
};

// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> grid{{1, 1}, {1, 1}};
  s.largestIsland(grid);
  return 0;
}