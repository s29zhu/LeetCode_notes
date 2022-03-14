#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    vector<bool> v(s.size(), true);
    stack<int> bp;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ')') {
        if (!bp.empty())
          bp.pop();
        else
          v[i] = false;
      } else if (s[i] == '(') {
        bp.push(i);
      }
    }
    while (!bp.empty()) {
      v[bp.top()] = false;
      bp.pop();
    }
    string rst;
    for (int i = 0; i < s.size(); ++i)
      if (v[i]) rst.push_back(s[i]);
    return rst;
  }
};
// @lc code=end
