#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
 public:
  bool wordBreak(const string& s, vector<string>& wordDict) {
    unordered_set<string> dict;
    for (auto& i : wordDict) dict.insert(i);
    auto exists = [&s, &dict](int start, int end) {
      return dict.find({s.begin() + start, s.begin() + end + 1}) != dict.end();
    };
    int N = s.size();
    vector<bool> avail(N, false);
    avail[0] = exists(0, 0);
    for (int i = 1; i < N; ++i) {
      if (exists(0, i)) {
        avail[i] = true;
        continue;
      }
      for (int j = i; j >= 1; --j) {
        if (avail[j - 1] && exists(j, i)) {
          avail[i] = true;
          break;
        }
      }
    }
    return avail.back();
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> wordDict{"a", "b"};
  bool rst = s.wordBreak("ab", wordDict);

  return 0;
}
