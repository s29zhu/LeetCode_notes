#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution {
 public:
  bool validPalindrome(string s) {
    bool skipped = false;
    int i = 0, j = s.size() - 1;
    is_palindrome_until(s, i, j);
    if (i >= j) return true;
    if (s[i + 1] == s[j] && s[i] == s[j - 1]) {
      int k = i + 1, l = j;
      is_palindrome_until(s, k, l);
      if (k >= l) return true;
      is_palindrome_until(s, i, --j);
    } else if (s[i + 1] == s[j]) {
      is_palindrome_until(s, ++i, j);
    } else if (s[i] == s[j - 1]) {
      is_palindrome_until(s, i, --j);
    }
    return i >= j;
  }
  void is_palindrome_until(const string& s, int& i, int& j) {
    for (; i < j; ++i, --j)
      if (s[i] != s[j]) return;
  }
};
// @lc code=end

int main() {
  string s("puufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupu");
  Solution a;
  a.validPalindrome(s);
  return 0;
}