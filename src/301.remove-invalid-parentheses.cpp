#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */

// @lc code=start
class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> rst;
    append(s, "", 0, 0, rst);
    return rst;
  }
  void append(const string& original, string s, int n, int sum,
              vector<string>& rst) {
    if (n == original.size()) {
      if (sum == 0) rst.push_back(move(s));
    } else {
      auto c = original[n];
      if (c != '(' && c != ')')
        append(original, s + c, n + 1, sum, rst);
      else {
        append(original, s, n + 1, sum, rst);
        append(original, s + c, n + 1, sum + c == '(' ? -1 : 1, rst);
      }
    }
  }
};
// @lc code=end
