#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
 public:
  vector<string> wordBreak(string s, const vector<string>& wordDict) {
    unordered_map<string, int> words;
    for (int i = 0; i < wordDict.size(); ++i) words[wordDict[i]] = i;

    vector<vector<pair<int, int>>> existing(s.size() + 1);
    existing[0] = vector<pair<int, int>>{{-1, -1}};

    for (int i = 1; i < s.size() + 1; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (existing[j].empty()) continue;
        auto iter = words.find({s.begin() + j, s.begin() + i});
        if (iter == words.end()) continue;
        existing[i].push_back(make_pair(j, iter->second));
      }
    }
    vector<string> rst;
    for (auto& i : existing.back()) {
      auto t = DFS(i, wordDict, existing);
      rst.insert(rst.end(), t.begin(), t.end());
    }
    return rst;
  }

  vector<string> DFS(const pair<int, int>& p, const vector<string>& wordDict,
                     const vector<vector<pair<int, int>>>& existing) {
    if (p.first == 0) return {wordDict[p.second]};
    vector<string> rst;
    for (auto& i : existing[p.first]) {
      auto t = DFS(i, wordDict, existing);
      rst.insert(rst.end(), t.begin(), t.end());
    }
    for (auto& i : rst) i.append(" " + wordDict[p.second]);
    return rst;
  }
};
// @lc code=end

int main() {
  Solution s;
  auto r = s.wordBreak("pineapplepenapple", {"apple","pen","applepen","pine","pineapple"});
  return 0;
}