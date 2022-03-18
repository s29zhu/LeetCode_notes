#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution {
 public:
  int calculate(string s) {
    int i = 0;
    int rst = 0, tmp = get_num(s, i);
    while (i < s.size()) {
      switch (s[i]) {
        case '+':
          rst += tmp;
          tmp = get_num(s, ++i);
          break;
        case '-':
          rst += tmp;
          tmp = -get_num(s, ++i);
          break;
        case '*':
          tmp *= get_num(s, ++i);
          break;
        case '/':
          tmp /= get_num(s, ++i);
          break;
        default:
          ++i;
      }
    }
    return rst + tmp;
  }
  int get_num(const string& s, int& i) {
    int rst = 0;
    while (i < s.size() && isspace(s[i])) ++i;
    while (i < s.size() && isdigit(s[i])) {
      rst *= 10;
      rst += s[i] - '0';
      ++i;
    }
    return rst;
  }
};
// @lc code=end

int main() {
  Solution s;
  s.calculate(" 3/2 ");
  return 0;
}