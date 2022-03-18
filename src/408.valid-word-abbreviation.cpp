#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=408 lang=cpp
 *
 * [408] Valid Word Abbreviation
 */

// @lc code=start
class Solution {
 public:
  bool validWordAbbreviation(string word, string abbr) {
    int i = 0, j = 0;
    while (i < word.size() && j < abbr.size()) {
      int n = get_number(abbr, j);
      if (n == -1) return false;
      i += n;
      if (!match_char(word, abbr, i, j)) return false;
    }
    if (i == word.size() && j == abbr.size()) return true;
    return false;
  }
  int get_number(const string& s, int& i) {
    if (s[i] == '0') return -1;
    int rst = 0;
    while (i < s.size() && isdigit(s[i])) {
      rst *= 10;
      rst += s[i] - '0';
      ++i;
    }
    return rst;
  }
  bool match_char(const string& w1, const string& w2, int& i, int& j) {
    for (; i < w1.size() && j < w2.size(); ++i, ++j)
      if (w1[i] != w2[j]) {
        if (isdigit(w2[j])) return true;
        return false;
      }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  s.validWordAbbreviation("internationalization", "i12iz4n");
  return 0;
}