#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
class Solution {
 public:
  int minAddToMakeValid(string s) {
    int l = 0, r = 0;
    for (auto i : s)
      if (i == '(')
        ++l;
      else if (l > 0)
        --l;
      else
        ++r;
    return r + l;
  }
};
// @lc code=end
