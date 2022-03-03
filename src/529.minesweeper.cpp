#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
class Solution {
  using Position = array<int, 2>;
  using Positions = vector<Position>;

 public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                   vector<int>& click) {
    if (board[click[0]][click[1]] == 'M') {
      board[click[0]][click[1]] = 'X';
      return board;
    }

    queue<Position> q;
    set<Position> visited;
    q.push(move(Position{click[0], click[1]}));
    visited.insert(q.front());

    while (!q.empty()) {
      auto t = move(q.front());
      q.pop();
      auto ns = move(neighbours(board, t));
      if (ns.second == 0) {
        board[t[0]][t[1]] = 'B';
        for (auto& i : ns.first)
          if (visited.find(i) == visited.end()) {
            q.push(i);
            visited.insert(i);
          }
      } else {
        board[t[0]][t[1]] = '0' + ns.second;
      }
    }

    return board;
  }
  pair<Positions, int> neighbours(vector<vector<char>>& board,
                                  const Position& q) {
    Positions ps;
    int max_row = board.size() - 1, max_col = board[0].size() - 1, n = 0;
    ps.reserve(8);
    for (int row = q[0] - 1; row <= q[0] + 1; ++row)
      for (int col = q[1] - 1; col <= q[1] + 1; ++col)
        if (row >= 0 && row <= max_row && col >= 0 && col <= max_col) {
          n += board[row][col] == 'M';
          ps.push_back(move(Position{row, col}));
        }
    ps.shrink_to_fit();
    return make_pair(ps, n);
  }
};
// @lc code=end
