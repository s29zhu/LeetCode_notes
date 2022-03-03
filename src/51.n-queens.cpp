#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
  using table = vector<vector<bool>>;

 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> all_queens;
    place_queen(table(n, vector<bool>(n, true)), all_queens, {}, 0);
    return all_queens;
  }

  void place_queen(const table& avail, vector<vector<string>>& all_queens,
                   const vector<string>& queens, int row) {
    if (row < avail.size()) {
      for (auto& col : check_avail(avail, row)) {
        vector<string> new_queens = queens;
        new_queens.emplace_back(avail.size(), '.');
        new_queens.back()[col] = 'Q';
        place_queen(update_avail(avail, row, col), all_queens, new_queens,
                    row + 1);
      }
    } else
      all_queens.push_back(queens);
  }

  table update_avail(const table& avail, int row, int col) {
    table rst = avail;
    for (int i = row + 1; i < avail.size(); ++i) {
      rst[i][col] = false;
      if (col + i - row < avail.size()) rst[i][col + i - row] = false;
      if (col - i + row >= 0) rst[i][col - i + row] = false;
    }
    return rst;
  }

  vector<int> check_avail(const table& avail, int row) {
    vector<int> rst;
    for (int i = 0; i < avail.size(); ++i)
      if (avail[row][i]) rst.push_back(i);
    return rst;
  }
};
// @lc code=end
