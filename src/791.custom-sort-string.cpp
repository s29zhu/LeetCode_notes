#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 */

// @lc code=start
class Solution {
 public:
  string customSortString(string order, string s) {
    unordered_map<char, int> indices;
    for (int i = 0; i < order.size(); ++i) indices[order[i]] = i;
    sort(s.begin(), s.end(),
         [&indices](char c1, char c2) { return indices[c1] < indices[c2]; });
    return s;
  }
};
// @lc code=end
