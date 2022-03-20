#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start
class Solution {
  int N;
  vector<int> islands{0, 0};

 public:
  int largestIsland(vector<vector<int>>& grid) {
    N = grid.size();
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j) BFS(i, j, grid);

    int rst = *max_element(islands.begin(), islands.end());
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        if (grid[i][j] == 0) rst = max(rst, largest(i, j, grid));

    return rst;
  }

  void BFS(int row, int col, vector<vector<int>>& grid) {
    if (grid[row][col] != 1) return;

    islands.push_back(1);
    int ii = islands.size() - 1;

    queue<array<int, 2>> q;
    q.push({row, col});
    grid[row][col] = ii;
    while (!q.empty()) {
      for (auto& i : neighbours(q.front()[0], q.front()[1]))
        if (grid[i[0]][i[1]] == 1) {
          grid[i[0]][i[1]] = ii;
          q.push(i);
          ++islands[ii];
        }
      q.pop();
    }
  }
  vector<array<int, 2>> neighbours(int row, int col) {
    vector<array<int, 2>> rst;
    if (row > 0) rst.push_back({row - 1, col});
    if (col > 0) rst.push_back({row, col - 1});
    if (row < N - 1) rst.push_back({row + 1, col});
    if (col < N - 1) rst.push_back({row, col + 1});
    return rst;
  }
  int largest(int row, int col, vector<vector<int>>& grid) {
    unordered_set<int> s;
    for (auto& i : neighbours(row, col)) if (grid[i[0]][i[1]] > 1) s.insert(grid[i[0]][i[1]]);
    int rst = 1;
    for (auto& i : s) rst += islands[i];
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