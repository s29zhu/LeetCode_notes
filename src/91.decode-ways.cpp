#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
 public:
  int numDecodings(const string& s) {
    auto n = [&s](int i) { return s[i] - '0'; };
    auto m = [&s, &n](int i) { return n(i - 1) * 10 + n(i); };
    int N = s.size();
    if (N == 1) return n(0) != 0;

    vector<int> v1(N, 1), v2(N, 0);
    for (int i = 1; i < N; ++i) {
      if (n(i) == 0 && (n(i - 1) == 0 || n(i - 1) > 2)) return 0;
      v1[i] = n(i) == 0 ? 0 : v1[i - 1] + v2[i - 1];
      v2[i] = m(i) > 26 ? 0 : v1[i - 1];
    }

    return v1.back() + v2.back();
  }
};
// @lc code=end

int main() {
  Solution s;
  int r = s.numDecodings("1211");
  cout << r << endl;
  return 0;
}