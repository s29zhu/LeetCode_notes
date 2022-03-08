#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    if (s.empty()) return true;
    for (int i = 0, j = 0; i < s.size(); ++j) {
      if (j == t.size()) return false;
      if (s[i] == t[j]) ++i;
    }
    return true;
  }
};
// @lc code=end
