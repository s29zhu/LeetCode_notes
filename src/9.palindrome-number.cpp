#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    string s = to_string(x);
    int N = (int)s.size();
    if (N == 1) return true;
    if (N % 2) {
      for (int i = 1; i <= N / 2; ++i)
        if (s[N / 2 + i] != s[N / 2 - i]) return false;
    } else {
      for (int i = N / 2 - 1, j = N / 2; j < N; --i, ++j)
        if (s[i] != s[j]) return false;
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  cout << boolalpha << s.isPalindrome(100) << endl;
  return 0;
}