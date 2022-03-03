#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=1945 lang=cpp
 *
 * [1945] Sum of Digits of String After Convert
 */

// @lc code=start
class Solution {
 public:
  int getLucky(string s, int k) {
    vector<int> digits = move(convert_digits(s));
    int rst = accumulate(digits.begin(), digits.end(), 0);
    for (int i = 1; i < k; ++i) rst = sum_digits(rst);
    return rst;
  }
  int sum_digits(int a) {
    int s = 0;
    for (int i = 1; i <= a; i *= 10) s += (a / i) % 10;
    return s;
  }
  vector<int> convert_digits(const string& s) {
    vector<int> rst;
    rst.reserve(s.size() * 2);
    for (auto& i : s) {
      if (i >= 't') {
        rst.push_back(2);
        rst.push_back(i - 't');
      } else if (i >= 'j') {
        rst.push_back(1);
        rst.push_back(i - 'j');
      } else {
        rst.push_back(i - 'a' + 1);
      }
    }
    rst.shrink_to_fit();
    return rst;
  }
};
// @lc code=end
